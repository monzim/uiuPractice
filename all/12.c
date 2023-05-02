#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *inputString(int size) {
  char *str = malloc((size + 1) * sizeof(char));
  fgets(str, size + 1, stdin);
  str[strcspn(str, "\n")] = '\0';

  return str;
}

int wordOccurrence(char *str, int len, char *search) {
  int count = 0;
  int searchLen = strlen(search);

  for (int i = 0; i <= len - searchLen; i++) {
    int time = 1;

    for (int j = 0; j < searchLen; j++) {
      if (str[i + j] != search[j]) {
        time = 0;
        break;
      }
    }

    if (time == 1) {
      count++;
    }
  }

  return count;
}
int main(int argc, char *argv[]) {
  char *str = inputString(100);
  char *word = inputString(100);

  int count = wordOccurrence(str, strlen(str), word);

  printf("%d", count);

    return EXIT_SUCCESS;
}
