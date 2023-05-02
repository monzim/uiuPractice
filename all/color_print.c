#include "color_print.h"

#include <stdarg.h>
#include <stdio.h>

void print_color(const char *color_code, const char *format, ...) {
  // Create a variable argument list
  va_list args;
  va_start(args, format);

  // Print the formatted text with color code
  printf("%s", color_code);
  vprintf(format, args);
  printf(ANSI_COLOR_RESET);

  // Clean up the variable argument list
  va_end(args);
}

void printRed(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_COLOR_RED);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printGreen(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_COLOR_GREEN);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printYellow(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_COLOR_YELLOW);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printBlue(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_COLOR_BLUE);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printMagenta(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_COLOR_MAGENTA);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printCyan(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_COLOR_CYAN);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printWhite(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_COLOR_WHITE);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printLightRed(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_COLOR_LIGHT_RED);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printLightGreen(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_COLOR_LIGHT_GREEN);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printLightYellow(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_COLOR_LIGHT_YELLOW);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printLightBlue(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_COLOR_LIGHT_BLUE);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printLightMagenta(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_COLOR_LIGHT_MAGENTA);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printLightCyan(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_COLOR_LIGHT_CYAN);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printLightWhite(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_COLOR_LIGHT_WHITE);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printGray(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_COLOR_GRAY);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

// BOLD COLORS
void printBoldRed(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_BOLD_RED);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printBoldGreen(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_BOLD_GREEN);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printBoldYellow(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_BOLD_YELLOW);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printBoldBlue(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_BOLD_BLUE);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printBoldMagenta(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_BOLD_MAGENTA);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printBoldCyan(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_BOLD_CYAN);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}

void printBoldWhite(const char *format, ...) {
  va_list args;
  va_start(args, format);

  printf(ANSI_BOLD_WHITE);
  vprintf(format, args);

  printf(ANSI_COLOR_RESET);
  va_end(args);
}
