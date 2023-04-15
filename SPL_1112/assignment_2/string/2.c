#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(int size) {
  char *str = malloc((size + 1) * sizeof(char));
  fgets(str, size + 1, stdin);

  return str;
}

char *joinString(char *str1, char *str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  char *str = malloc((len1 + len2 + 1) * sizeof(char));

  for (int i = 0; i < len1; i++) {
    str[i] = str1[i];
  }

  for (int i = 0; i < len2; i++) {
    str[len1 + i] = str2[i];
  }

  str[len1 + len2] = '\0';

  return str;
}

int main(int argc, char *argv[]) {
  char *str1 = inputString(100);
  char *str2 = inputString(100);

  char *str = joinString(str1, str2);
  printf("%s", str);

  return EXIT_SUCCESS;
}
