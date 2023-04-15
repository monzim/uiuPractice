#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sLen(char str[]) {
  int length = 0;
  while (str[length] != '\0') {
    length++;
  }
  return length;
}

char *inputString(int size, int removeNewLine) {
  char *str = malloc((size + 1) * sizeof(char));
  fgets(str, size + 1, stdin);
  if (removeNewLine) {
    str[strcspn(str, "\n")] = '\0';
  }

  return str;
}

int main(int argc, char *argv[]) {
  char *str = inputString(100, true);

  int length = sLen(str);

  printf("The length: %d", length);
  return EXIT_SUCCESS;
}
