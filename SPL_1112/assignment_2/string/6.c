#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(int size) {
  char *str = malloc((size + 1) * sizeof(char));
  fgets(str, size + 1, stdin);

  return str;
}

void toUpperCase(char *str, int len) {
  for (int i = 0; str[i] != '\0'; i++) {
    char s = str[i];

    if (s >= 'a' && s <= 'z') {
      str[i] = s - 32;
    }
  }
}

int main(int argc, char *argv[]) {
  char *str = inputString(100);
  toUpperCase(str, strlen(str));

  printf("%s", str);
  return EXIT_SUCCESS;
}
