#include "setup.h"

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../config/config.h"
#include "../helper/color_print.h"
#include "../helper/encrypt.h"
#include "../helper/file_writer.h"
#include "../helper/log.h"

void print_app_title(int isFirstTime) {
  printf("\n");
  printBoldYellow("***********************************************\n");
  printBoldYellow("*                                             *\n");
  if (isFirstTime) {
    printBoldYellow("*              WEATHER BOT APP                 *\n");
  } else {
    printBoldYellow("*              WELCOME BACK!                  *\n");
  }
  printBoldYellow("*                                             *\n");
  printBoldYellow("***********************************************\n");
}

void print_startup_message() {
  addLog("Printing startup message...");
  print_app_title(1);
  printf("\n");
  printCyan("Welcome to the Weather Bot App!\n");
  printf("\n");
  printf("\n");
  printWhite("This app provides weather information for your location.\n");
  printWhite("Please make sure you have obtained an API key from");
  printBlue(" weatherapi.com.\n");
  printWhite("You can get one for free at");
  printBlue(" https://www.weatherapi.com.\n");
  printf("\n");
  printWhite("Also, set up a Discord webhook to receive weather data in your Discord server.\n");
  printWhite("You can get one for free at");
  printBlue(" https://support.discord.com/hc/en-us/articles/228383668-Intro-to-Webhooks.\n");
  printf("\n");
  printf("\n");
  printMagenta("Let's get started!\n");
  printf("\n");
}

void checkIfFirstTimeRunning() {
  if (access(APP_CONFIG_FILE, F_OK) != -1) {
    addLog("App has been run before.");
    print_app_title(0);
  } else {
    addLog("App has not been run before.");
    print_startup_message();
    getSaveApiWebhookEnvironmentVarSetup();
  }
}

void createDirectoryIfNotExists(char *dir) {
  if (access(dir, F_OK) != -1) {
    addLog("Directory %s exists.", dir);
  } else {
    addLog("Directory %s does not exist. Creating...", dir);
    mkdir(dir, 0777);
  }
}

void initialSetup() {
  addLog("");

  // create three directories
  createDirectoryIfNotExists("app_folder");
  createDirectoryIfNotExists("app_folder/logs");
  createDirectoryIfNotExists("app_folder/cache");
  createDirectoryIfNotExists("app_folder/settings");

  loadEncryptionKeyFromEnv();

  checkIfFirstTimeRunning();

  loadEnvironemntFromFile();
}