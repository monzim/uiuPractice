#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(int size, bool removeNewLine) {
  char *str = malloc((size + 1) * sizeof(char));
  fgets(str, size + 1, stdin);
  if (removeNewLine) {
    str[strcspn(str, "\n")] = '\0';
  }

  return str;
}

char getMaxChar(char *str, int len) {
  int maxCount = 0;
  char maxChar = '\0';

  for (int i = 0; i < len; i++) {
    int count = 0;

    for (int j = i + 1; j < len; j++) {
      if (str[i] == str[j]) {
        count++;
      }
    }

    if (count > maxCount) {
      maxCount = count;
      maxChar = str[i];
    }
  }

  return maxChar;
}

char toLower(char c) {
  if (c >= 'A' && c <= 'Z') {
    return c + 32;
  }

  return c;
}

char toUpper(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - 32;
  }

  return c;
}

int main(int argc, char *argv[]) {
  char *str = inputString(100, true);

  char max = getMaxChar(str, strlen(str));
  printf("%c (or %c)", toUpper(max), toLower(max));

  return EXIT_SUCCESS;
}
