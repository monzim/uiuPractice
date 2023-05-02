#include "encrypt.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../config/config.h"
#include "../helper/color_print.h"
#include "../helper/log.h"

const char *ENCRYPTION_KEY = "";

char *generateRandomString() {
  srand(time(0));
  char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  int charsetLength = sizeof(charset) - 1;
  char *randomString = (char *)malloc(33 * sizeof(char));

  for (int i = 0; i < 32; i++) {
    int index = rand() % charsetLength;
    randomString[i] = charset[index];
  }

  randomString[32] = '\0';

  return randomString;
}

void systemAESEncriptDecripter(char *text, bool isEncrypt) {
  // text memory address
  char **textAddress = &text;

  char command[256];

  if (ENCRYPTION_KEY == NULL || strlen(ENCRYPTION_KEY) == 0) {
    addLog("systemAESEncriptDecripter: Encryption key not found in .env file");

    printRed("Encryption key not found in .env file\n");
    printRed("Please add 32 character long encryption key in .env file\n");
    loadEncryptionKeyFromEnv();
  }

  if (isEncrypt) {
    sprintf(command, "./lib/bin/encripter e %s \"%s\"", ENCRYPTION_KEY, text);
  } else {
    sprintf(command, "./lib/bin/encripter d %s \"%s\"", ENCRYPTION_KEY, text);
  }

  FILE *fp = popen(command, "r");

  if (fp == NULL) {
    addLog("systemAESEncriptDecripter: Failed to open process, command: %s", command);
    printf("Failed to open process\n");
  }

  char buffer[1048];
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    strcpy(text, buffer);
  }

  pclose(fp);
}

void loadEncryptionKeyFromEnv() {
  FILE *envFile = fopen(APP_ENV_FILE, "r");

  if (envFile != NULL) {
    char line[256];

    while (fgets(line, sizeof(line), envFile)) {
      if (strncmp(line, "ENCRYPTION_KEY=", 15) == 0) {
        char *key = strdup(line + 15);
        key[strcspn(key, "\n")] = 0;

        ENCRYPTION_KEY = strdup(key);
        free(key);
        addLog("loadEncryptionKeyFromEnv: Encryption key loaded");
        break;
      }

      addLog("loadEncryptionKeyFromEnv: Encryption key not found in .env file");
    }

    fclose(envFile);
  } else {
    addLog("loadEncryptionKeyFromEnv: .env file not found");

    FILE *envFile = fopen(APP_ENV_FILE, "w");
    char *randomString = generateRandomString();

    fprintf(envFile, "ENCRYPTION_KEY=%s", randomString);

    fclose(envFile);
    loadEncryptionKeyFromEnv();
  }
}

// Function to encrypt input
void encryptInput(char *input) {
  // encrypt input
  // addLog("encryptInput: Encrypting input: %s", input);
  systemAESEncriptDecripter(input, true);
}

// Function to decrypt input
void decryptInput(char *input) {
  // decrypt input
  // addLog("decryptInput: Decrypting input: %s", input);
  systemAESEncriptDecripter(input, false);
}

void systemAESEncriptDecripterWithKey(char *text, bool isEncrypt, char *key) {
  char **textAddress = &text;
  char command[1024];

  if (strlen(key) != 32) {
    printRed("\nKey length is not 32\n");
    printRed("Need 32 character long key to encrypt/decrypt\n");
    printRed("___________________________________________\n");
    addLog("systemAESEncriptDecripterWithKey: key length is not 32");
    return;
  }

  if (isEncrypt) {
    sprintf(command, "./lib/bin/encripter e %s \"%s\"", key, text);
  } else {
    sprintf(command, "./lib/bin/encripter d %s \"%s\"", key, text);
  }

  FILE *fp = popen(command, "r");

  if (fp == NULL) {
    addLog("systemAESEncriptDecripterWithKey: Failed to open process, command: %s", command);
    printf("Failed to open process\n");
  }

  char buffer[1048];
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    strcpy(text, buffer);
  }

  pclose(fp);
}

void encryptTextWithKey(char *input, char *key) {
  // encrypt
  addLog("encryptTextWithKey: Encrypting input with key");
  systemAESEncriptDecripterWithKey(input, true, key);
}

void decryptTextWithKey(char *input, char *key) {
  // decrypt input
  addLog("decryptTextWithKey: Decrypting input with key");
  systemAESEncriptDecripterWithKey(input, false, key);
}