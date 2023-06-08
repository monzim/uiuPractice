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

int find_substr(char *a, char *b) {
  int strLen = strlen(a);
  int substrLen = strlen(b);

  int i, j;

  for (i = 0; i <= strLen - substrLen; i++) {
    for (j = 0; j < substrLen; j++) {
      if (a[i + j] != b[j]) {
        break;
      }
    }

    if (j == substrLen) {
      return 1;
    }
  }

  return -1;
}

int main(int argc, char *argv[]) {
  char *str = inputString(100, true);
  char *substr = inputString(100, true);

  int index = find_substr(str, substr);

  printf("%d", index);

  return EXIT_SUCCESS;
}
