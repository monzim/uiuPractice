#include <stdio.h>

int main() {
  char findChar = 'a';
  char text[100];

  printf("Enter some text: ");
  scanf("%s", text);

  int size = sizeof(text) / sizeof(text[0]);

  for (size_t i = 0; i < size; i++) {
    if (text[i] == findChar) {
      printf("%ld", i + 1);
      break;
    } else if (i == size - 1) {
      printf("-1");
    }
  }

  return 0;
}