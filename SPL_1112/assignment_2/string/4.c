#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(int size) {
  char *str = malloc((size + 1) * sizeof(char));
  fgets(str, size + 1, stdin);

  return str;
}

int wordCounter(char *str, int len) {
  int count = 0;

  for (int i = 0; i < len; i++) {
    char c = str[i];

    if (c == ' ') {
      count++;
    }
  }

  return count + 1;
}

int main(int argc, char *argv[]) {
  char *str = inputString(100);

  int count = wordCounter(str, strlen(str));
  printf("%d", count);

  return EXIT_SUCCESS;
}
