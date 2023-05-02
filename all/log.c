#include "log.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../config/config.h"
#include "../helper/color_print.h"

void addLog(const char* logMessage, ...) {
  time_t rawTime;
  struct tm* timeInfo;
  time(&rawTime);
  timeInfo = localtime(&rawTime);

  FILE* logFile = fopen(APP_LOG_FILE, "a");

  if (logFile == NULL) {
    printf("Failed to open log file! Creating a new one...\n");
    logFile = fopen(APP_LOG_FILE, "w");
    if (logFile == NULL) {
      printf("Error creating log file.\n");
      exit(1);
    }
  }

  char timestamp[20];
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeInfo);

  va_list args;
  va_start(args, logMessage);
  fprintf(logFile, "[%s] ", timestamp);
  vfprintf(logFile, logMessage, args);
  fprintf(logFile, "\n");
  va_end(args);

  fclose(logFile);
}

void viewAllLogs() {
  printMagenta("All logs:\n");

  FILE* file = fopen(APP_LOG_FILE, "r");

  if (file == NULL) {
    printRed("Error opening log file.\n");
    addLog("Error opening log file.");
    return;
  }

  char line[256];
  printGray("____________________________________________________\n\n");
  while (fgets(line, sizeof(line), file) != NULL) {
    printf("%s", line);
  }

  printGray("____________________________________________________\n\n");

  fclose(file);
  addLog("Viewed all logs.");
}

void viewLogsBetweenDates() {
  FILE* file = fopen(APP_LOG_FILE, "r");

  if (file == NULL) {
    printRed("Error opening log file.\n");
    addLog("Error opening log file.");
    return;
  }

  int startLogs = 0;

  char logDate[20];
  char startDate[20];
  char endDate[20];

  printf("  • Enter start date in format [YYYY-MM-DD HH:MM:SS]: ");
  scanf(" %[^\n]", startDate);

  printf("  • Enter end date in format [YYYY-MM-DD HH:MM:SS]: ");
  scanf(" %[^\n]", endDate);
  printf("\n");

  char line[256];
  printMagenta("Logs between dates:\n");
  printGray("____________________________________________________\n\n");

  struct tm tmStartDate;
  struct tm tmEndDate;
  strptime(startDate, "%Y-%m-%d %H:%M:%S", &tmStartDate);
  strptime(endDate, "%Y-%m-%d %H:%M:%S", &tmEndDate);
  mktime(&tmStartDate);
  mktime(&tmEndDate);

  while (fgets(line, sizeof(line), file) != NULL) {
    strncpy(logDate, line + 1, 19);
    logDate[19] = '\0';

    struct tm tmLogDate;
    strptime(logDate, "%Y-%m-%d %H:%M:%S", &tmLogDate);
    time_t logTime = mktime(&tmLogDate);

    if (difftime(logTime, mktime(&tmStartDate)) >= 0 && difftime(logTime, mktime(&tmEndDate)) <= 0) {
      printf("%s", line);
      startLogs = 1;
    } else if (startLogs && difftime(logTime, mktime(&tmEndDate)) > 0) {
      break;
    }
  }

  printGray("____________________________________________________\n\n");

  fclose(file);
  addLog("Viewed logs between dates. Start date: %s, End date: %s", startDate, endDate);
}

void clearAppLogs() {
  printYellow("*** Clearing logs ***\n");

  FILE* file = fopen(APP_LOG_FILE, "w");

  if (file == NULL) {
    printRed("Error opening log file.\n");
    return;
  }

  fclose(file);
  printGreen("All App logs cleared.\n");
  printGray("--------------------------------------------\n");
  addLog("Cleared all logs.");
}