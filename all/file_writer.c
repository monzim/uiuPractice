#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "../config/config.h"
#include "../helper/color_print.h"
#include "../helper/encrypt.h"
#include "../helper/log.h"

// Function for storing buffer contents into a file
void writeBufferToFile(const char *filename, const void *buffer, size_t size, bool printLog) {
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    fprintf(stderr, "Failed to create file: %s\n", filename);
    return;
  }
  fwrite(buffer, 1, size, file);
  fclose(file);

  if (printLog) printf("Buffer contents written to file: %s\n", filename);
}

// Function to get user input and save to INI file
void getSaveApiWebhookEnvironmentVarSetup() {
  addLog("getSaveApiWebhookEnvironmentVarSetup: Getting API_KEY and DISCORD_WEBHOOK from user");

  char api_key[256];
  char discord_webhook[256];

  char tempAPI_KEY[256];
  char tempDISCORD_WEBHOOK[256];

  printBoldWhite("Enter WEATHER_API_KEY: ");
  scanf("%s", api_key);
  getchar();
  addLog("getSaveApiWebhookEnvironmentVarSetup: API_KEY entered by user");

  if (strlen(api_key) == 0) {
    addLog("getSaveApiWebhookEnvironmentVarSetup: API_KEY is empty");
    printRed("API_KEY cannot be empty. Please try again.\n");
    getSaveApiWebhookEnvironmentVarSetup();
  }

  api_key[strcspn(api_key, "\n")] = 0;
  strcpy(tempAPI_KEY, api_key);

  // Encrypt API_KEY
  encryptInput(api_key);
  API_KEY = strdup(api_key);

  printBoldWhite("Enter DISCORD_WEBHOOK: ");
  scanf("%s", discord_webhook);
  getchar();

  addLog("getSaveApiWebhookEnvironmentVarSetup: DISCORD_WEBHOOK entered by user");

  if (strlen(discord_webhook) == 0) {
    addLog("getSaveApiWebhookEnvironmentVarSetup: DISCORD_WEBHOOK is empty");
    printRed("DISCORD_WEBHOOK cannot be empty. Please try again.\n");
    getSaveApiWebhookEnvironmentVarSetup();
  }

  discord_webhook[strcspn(discord_webhook, "\n")] = 0;
  strcpy(tempDISCORD_WEBHOOK, discord_webhook);

  // Encrypt DISCORD_WEBHOOK
  FILE *file = fopen(APP_CONFIG_FILE, "w");

  if (file != NULL) {
    // addLog("getSaveApiWebhookEnvironmentVarSetup: config.ini file opened successfully");

    fprintf(file, "[CONFIG]\n");
    fprintf(file, "API_KEY=%s\n", API_KEY);

    int len = strlen(discord_webhook);
    int num_segments = (len + 59) / 60;  // calculate number of segments
    fprintf(file, "DISCORD_WEBHOOK_SEGMENTS=%d\n", num_segments);

    for (int i = 0; i < num_segments; i++) {
      char segment_name[32];
      char segment[61];  // Buffer to store each segment (including null terminator)

      snprintf(segment_name, sizeof(segment_name), "DISCORD_WEBHOOK_%d", i + 1);  // Create segment name
      strncpy(segment, &discord_webhook[i * 60], 60);  // Copy 60 characters from discord_webhook to segment
      segment[60] = '\0';                              // Null terminate the segment
      // encryptInput(segment);                           // Encrypt the segment

      // Store the encrypted segment in a temporary variable temp_segment
      char *temp_segment;
      strncpy(temp_segment, segment, 60);
      temp_segment[60] = '\0';

      encryptInput(temp_segment);                            // Encrypt the temp_segment
      fprintf(file, "%s=%s\n", segment_name, temp_segment);  // Print the temp_segment in the config file
    }

    fclose(file);

    addLog("getSaveApiWebhookEnvironmentVarSetup: API_KEY and DISCORD_WEBHOOK saved to config.ini file successfully");
    print_color(ANSI_COLOR_LIGHT_YELLOW, "\nSuccessfully saved API_KEY and DISCORD_WEBHOOK to config.ini file.\n");
  } else {
    addLog("getSaveApiWebhookEnvironmentVarSetup: Failed to open config.ini file");
    printRed("Failed to save API_KEY and DISCORD_WEBHOOK to config.ini file.\n");
  }

  // Set API_KEY and DISCORD_WEBHOOK to temp values so that they can be used in the program
  API_KEY = strdup(tempAPI_KEY);
  DISCORD_WEBHOOK = strdup(tempDISCORD_WEBHOOK);

  addLog("getSaveApiWebhookEnvironmentVarSetup: API_KEY and DISCORD_WEBHOOK set");
}

// Function to load saved input from config.ini file
void loadEnvironemntFromFile() {
  char api_key[256];
  char discord_webhook[1024] = "\0";
  int total_segments = 0;

  FILE *file = fopen(APP_CONFIG_FILE, "r");

  if (file != NULL) {
    char line[256];

    while (fgets(line, sizeof(line), file)) {
      if (strncmp(line, "API_KEY=", 8) == 0) {
        strncpy(api_key, line + 8, sizeof(api_key));
        api_key[strcspn(api_key, "\n")] = 0;

        decryptInput(api_key);
        API_KEY = strdup(api_key);
        API_KEY[strcspn(API_KEY, "\n")] = 0;

        addLog("loadEnvironemntFromFile: API_KEY loaded successfully");

      } else if (strncmp(line, "DISCORD_WEBHOOK_SEGMENTS=", 25) == 0) {
        int num_segments;

        sscanf(line + 25, "%d", &num_segments);
        total_segments = num_segments;

        addLog("loadEnvironemntFromFile: DISCORD_WEBHOOK_SEGMENTS loaded successfully");
      }

      else if (strncmp(line, "DISCORD_WEBHOOK_", 16) == 0) {
        char segment_name[32];
        char segment_value[1024];
        int i;

        for (i = 0; i < total_segments; i++) {
          snprintf(segment_name, sizeof(segment_name), "DISCORD_WEBHOOK_%d", i + 1);

          if (strncmp(line, segment_name, strlen(segment_name)) == 0) {
            strncpy(segment_value, line + strlen(segment_name) + 1, sizeof(segment_value));
            segment_value[strcspn(segment_value, "\n")] = '\0';

            // printf("%d: %s\n", i, segment_value);
            decryptInput(segment_value);
            // printRed("%d: %s\n", i, segment_value);

            segment_value[strcspn(segment_value, "\n")] = '\0';  // Remove newline character

            strncat(discord_webhook, segment_value, sizeof(discord_webhook) - strlen(discord_webhook) - 1);
          }
        }
      }
    }

    DISCORD_WEBHOOK = strdup(discord_webhook);
    DISCORD_WEBHOOK[strcspn(DISCORD_WEBHOOK, "\n")] = 0;
    addLog("loadEnvironemntFromFile: DISCORD_WEBHOOK loaded successfully");

    fclose(file);
  }
}