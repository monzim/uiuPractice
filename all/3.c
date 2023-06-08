#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(int size) {
  char *str = malloc((size + 1) * sizeof(char));
  fgets(str, size + 1, stdin);

  return str;
}

int vowelCount(char *str, int len) {
  int count = 0;

  for (int i = 0; i < len; i++) {
    char c = str[i];

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' ||
        c == 'U') {
      count++;
    }
  }

  return count;
}

int main(int argc, char *argv[]) {
  char *sst = inputString(100);
  int len = strlen(sst);

  int count = vowelCount(sst, len);
  printf("%d", count);

  return EXIT_SUCCESS;
}
