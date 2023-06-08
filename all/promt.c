#include "promt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../api/api_fetch_current.h"
#include "../api/discord.h"
#include "../config/config.h"
#include "../helper/color_print.h"
#include "../helper/encrypt.h"
#include "../helper/file_writer.h"
#include "../helper/log.h"
#include "../helper/setup.h"
#include "../models/models.h"

void printColorYesNo() {
  printBoldWhite("(");
  printBoldGreen("y");
  printf("/");
  printLightRed("n");
  printBoldWhite("): ");
}

void printAborting() {
  // printBoldWhite("Aborting...\n");
  printRed("Aborting...\n");
}

void askGetCurrentWeather() {
  char location[256];
  printf("Enter location: ");
  scanf("%s", location);

  WeatherData data = fetchCurrentWeatherWithLocation(location, RESPONSE_FILE, true, true);

  char send_message;
  printf("• Do you want to send message to discord? ");
  printColorYesNo();
  scanf(" %c", &send_message);

  if (send_message == 'Y' || send_message == 'y') {
    struct DiscordMessage discordMessage = generateDiscordMessage(data);
    sendMessageToDiscord(DISCORD_WEBHOOK, &discordMessage);
  }
}

void askHandleLogsView() {
  char option;

  printf("  1. ");
  printLightCyan("View all logs\n");

  printf("  2. ");
  printLightCyan("View logs between a date range\n");

  printf("  0. ");
  printLightCyan("Go Back\n");
  printf("\n");

  printf("  Choose an option: ");
  scanf(" %c", &option);
  printf("\n");

  char confirm;
  char logDate[20];
  char startDate[20];
  char endDate[20];

  switch (option) {
    case '0':
      break;

    case '1':
      printBoldWhite("  • Are you sure you want to view all logs? ");
      printColorYesNo();
      scanf(" %c", &confirm);

      if (confirm == 'Y' || confirm == 'y') {
        printf("\n");
        viewAllLogs();
      }

      break;

    case '2':

      viewLogsBetweenDates();
      break;

    default:
      printRed("  You have entered an invalid option. Aborting...\n");
      break;
  }
}

void askClearLogs() {
  char confirm;
  printBoldWhite("  • Are you sure you want to clear logs? ");
  printColorYesNo();
  scanf(" %c", &confirm);

  if (confirm == 'Y' || confirm == 'y') {
    printf("\n");
    clearAppLogs();
  }
}

void askResetConfig() {
  char confirm;
  char confirm2;

  printLightRed("  • Are you sure you want to reset config? ");
  printColorYesNo();
  scanf(" %c", &confirm);

  if (confirm == 'Y' || confirm == 'y') {
    char final[2];

    printBoldRed(
        "  • Final confirmation. You have to re-enter your API key and Discord Webhook. Are you sure you want to reset "
        "config? ");
    printColorYesNo();
    scanf(" %c", &confirm2);

    if (confirm2 == 'Y' || confirm2 == 'y') {
      resetConfig();
    }
  }
}

void askEncriptDecriptText() {
  char option;
  char *text = NULL;
  char *temp = NULL;
  char key[33];

  printf("  1. ");
  printLightCyan("Encrypt text\n");

  printf("  2. ");
  printLightCyan("Decrypt text\n");

  printf("  0. ");
  printLightCyan("Go Back\n");
  printf("\n");

  printf("  Choose an option: ");
  scanf(" %c", &option);
  printf("\n");

  switch (option) {
    case '0':
      break;

    case '1':
      printLightBlue(" ⁍ Enter text to encrypt: ");
      getchar();

      text = (char *)malloc(sizeof(char) * 2000);
      fgets(text, 1000, stdin);
      text[strcspn(text, "\n")] = '\0';

      printLightMagenta(" ⁍ Enter key: ");
      fgets(key, sizeof(key), stdin);
      key[strcspn(key, "\n")] = '\0';

      temp = (char *)malloc(sizeof(char) * (strlen(text) + 1));
      strcpy(temp, text);

      encryptTextWithKey(text, key);
      text[strcspn(text, "\n")] = '\0';

      if (strlen(text) != strlen(temp)) {
        printGreen("\nEncrypted text\n");
        printGray("______________________________________________________\n");
        printBoldWhite("\n%s", text);
        printGray("\n______________________________________________________\n");
        printYellow("  (You can decrypt this text with the same key)\n");
        break;
      } else {
        printRed("  Error: Something went wrong. Aborting...\n");
        break;
      }

    case '2':
      printLightBlue(" ⁍ Enter text to decrypt: ");
      getchar();

      text = (char *)malloc(sizeof(char) * 2000);
      fgets(text, 1000, stdin);
      text[strcspn(text, "\n")] = '\0';

      printLightMagenta(" ⁍ Enter key: ");
      fgets(key, sizeof(key), stdin);
      key[strcspn(key, "\n")] = '\0';

      temp = (char *)malloc(sizeof(char) * (strlen(text) + 1));
      strcpy(temp, text);

      decryptTextWithKey(text, key);
      text[strcspn(text, "\n")] = '\0';

      if (strlen(text) != strlen(temp)) {
        printGreen("\nDecrypted text\n");
        printGray("______________________________________________________\n");
        printBoldWhite("\n%s", text);
        printGray("\n______________________________________________________\n");
        break;
      } else {
        printRed("  Error: Something went wrong. Aborting...\n");
        break;
      }

    default:
      printRed("  You have entered an invalid option. Aborting...\n");
      break;
  }
}

void askChangeAPIKey() {
  printLightBlue("  ⁍ Enter new API key: ");
  char api_key[100];
  scanf("%s", api_key);

  char confirm;
  printLightRed("  • Are you sure you want to change API key? ");
  printColorYesNo();
  scanf(" %c", &confirm);

  if (confirm == 'Y' || confirm == 'y') {
    changeApiKey(api_key);
  }
}

void askChangeDiscordWebhook() {
  printLightBlue("  ⁍ Enter new Discord Webhook: ");
  char discord_webhook[100];
  scanf("%s", discord_webhook);

  char confirm;
  printLightRed("  • Are you sure you want to change Discord Webhook? ");
  printColorYesNo();
  scanf(" %c", &confirm);

  if (confirm == 'Y' || confirm == 'y') {
    // TODO: Implement this
  }
}