#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(int size) {
  char *str = malloc((size + 1) * sizeof(char));
  fgets(str, size + 1, stdin);

  return str;
}

char *reverseString(char *str, int len) {
  char *rev = malloc((len + 1) * sizeof(char));

  for (int i = 0; i < len; i++) {
    rev[i] = str[len - i - 1];
  }

  rev[len] = '\0';

  return rev;
}

int main(int argc, char *argv[]) {
  char *sst = inputString(100);

  char *rev = reverseString(sst, strlen(sst));
  printf("%s", rev);

  return EXIT_SUCCESS;
}
