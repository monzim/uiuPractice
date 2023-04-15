#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(int size) {
  char *str = malloc((size + 1) * sizeof(char));
  fgets(str, size + 1, stdin);

  return str;
}

int howManyTime(char *str, int len, char c) {
  int count = 0;

  for (int i = 0; i < len; i++) {
    if (str[i] == c) {
      count++;
    }
  }

  return count;
}

int main(int argc, char *argv[]) {
  char *str = inputString(100);
  int len = strlen(str);

  char *s = inputString(1);

  int count = howManyTime(str, len, s[0]);
  printf("%d", count);

  return EXIT_SUCCESS;
}
