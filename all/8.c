#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(int size) {
  char *str = malloc((size + 1) * sizeof(char));
  fgets(str, size + 1, stdin);

  return str;
}

void sortInAlpOrder(char *str, int len) {
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (str[i] > str[j]) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  char *str = inputString(100);
  sortInAlpOrder(str, strlen(str));

  printf("%s", str);

  return EXIT_SUCCESS;
}
