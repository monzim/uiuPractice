#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(int size) {
  char *str = malloc((size + 1) * sizeof(char));
  fgets(str, size + 1, stdin);
  str[strcspn(str, "\n")] = '\0';

  return str;
}

void removeDuplicates(char *str, int len) {
  for (int i = 0; i < len; i++) {
    char c = str[i];

    for (int j = i + 1; j < len; j++) {
      if (str[j] == c) {
        for (int k = j; k < len; k++) {
          str[k] = str[k + 1];
        }
        len--;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  char *str = inputString(100);

  removeDuplicates(str, strlen(str));

  printf("%s", str);

  return EXIT_SUCCESS;
}
