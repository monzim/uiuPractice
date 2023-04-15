#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *input_string(int size) {
  char *str = malloc((size + 1) * sizeof(char));
  fgets(str, size + 1, stdin);

  return str;
}

int stringlen(char *str) {
  int len = 0;
  while (*str != '\0') {
    len++;
    str++;
  }

  return len;
}

int main(int argc, char *argv[]) {
  char *str = input_string(100);

  int len = stringlen(str);
  printf("%d", len);

  return EXIT_SUCCESS;
}
