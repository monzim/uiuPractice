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

char *reverseWords(char *str, int len) {
  char *result = malloc(len * sizeof(char));

  char *words[len];
  int wordCount = 0;
  char *word = strtok(str, " ");
  while (word != NULL) {
    words[wordCount++] = word;
    word = strtok(NULL, " ");
  }

  for (int i = 0; i < wordCount / 2; i++) {
    char *temp = words[i];
    words[i] = words[wordCount - i - 1];
    words[wordCount - i - 1] = temp;
  }

  for (int i = 0; i < wordCount; i++) {
    strcat(result, words[i]);
    if (i != wordCount - 1) {
      strcat(result, " ");
    }
  }

  return result;
}

int main(int argc, char *argv[]) {
  char *str = inputString(100, true);
  char *result = reverseWords(str, strlen(str));

  printf("%s", result);

  return EXIT_SUCCESS;
}
