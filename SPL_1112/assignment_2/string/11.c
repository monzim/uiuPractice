#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(int size) {
  char *str = malloc((size + 1) * sizeof(char));
  fgets(str, size + 1, stdin);

  return str;
}

bool isDigit(char c) {
  int k = c >= '0' && c <= '9';
  return k;
}

int main(int argc, char *argv[]) {
  char *str = inputString(100);

  int count = 0;
  for (int i = 0; i < strlen(str); i++) {
    char c = str[i];
    if (isDigit(c)) {
      count++;
    }
  }

  printf("%d", count);

  return EXIT_SUCCESS;
}
