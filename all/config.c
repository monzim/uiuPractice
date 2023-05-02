// config.c

#include "config.h"

#include <stdio.h>
#include <stdlib.h>

#include "../helper/color_print.h"
#include "../helper/encrypt.h"
#include "../helper/log.h"
#include "../helper/setup.h"

char* API_KEY = "\0";
const char* BASE_URL = "http://api.weatherapi.com/v1";
const char* CURENT_WEATHER_REQUEST = "/current.json";

char* DISCORD_WEBHOOK = "\0";

const char* BOT_AVATAR_URL = "https://res.monzim.com/others/avatar/_791550a1-faaa-4b3e-b7cf-8151b2056028.jpeg";

const char* BOT_NAME = "Weather Bot";

// FILE
const char* APP_FOLDER = "app_folder";
const char* APP_LOGS_DIR = "app_folder/logs";
const char* APP_CACHE_DIR = "app_folder/cache";
const char* APP_SETTINGS_DIR = "app_folder/settings";

// File paths
const char* APP_CONFIG_FILE = "app_folder/settings/config.ini";
const char* APP_ENV_FILE = "app_folder/settings/.env";
const char* APP_LOG_FILE = "app_folder/logs/app.log";
const char* RESPONSE_FILE = "app_folder/cache/response.json";
const char* APP_CONFIG_FILE_TEMP = "app_folder/settings/temp_config.ini";

void resetConfig() {
  printRed("\n*** Resetting config ***\n");
  clearAppLogs();

  if (remove(APP_CONFIG_FILE) == 0) {
    printLightRed("Successfully deleted the config file.\n");
    printBoldRed("App config reset successfully!\n");
    addLog("App config reset successfully!");
  } else {
    printf("Unable to delete the file.\n");
    printBoldRed("App config reset failed!\n");
  }

  printLightRed("--------------------------------------------\n");
  initialSetup();
}

void changeApiKey(char* newApiKey) {
  // Open the config.ini file in read mode
  FILE* file = fopen(APP_CONFIG_FILE, "r");

  if (file == NULL) {
    printf("Error: Unable to open config.ini file\n");
    addLog("Change API Key failed! Unable to open config.ini file");
    return;
  }

  // Create a temporary file to write updated contents
  FILE* tempFile = fopen(APP_CONFIG_FILE_TEMP, "w");

  if (tempFile == NULL) {
    printf("Error: Unable to create temporary file\n");
    addLog("Change API Key failed! Unable to create temporary file");
    fclose(file);
    return;
  }

  encryptInput(newApiKey);

  char line[512];
  while (fgets(line, sizeof(line), file)) {
    if (strstr(line, "API_KEY=") == line) {
      fprintf(tempFile, "API_KEY=%s\n", newApiKey);
    } else {
      fputs(line, tempFile);
    }
  }

  fclose(file);
  fclose(tempFile);

  remove(APP_CONFIG_FILE);

  rename(APP_CONFIG_FILE_TEMP, APP_CONFIG_FILE);

  printBoldGreen("\nAPI_KEY updated successfully!\n");
  printLightGreen("--------------------------------------------\n");
  addLog("API_KEY updated successfully!");
  API_KEY = newApiKey;
}
