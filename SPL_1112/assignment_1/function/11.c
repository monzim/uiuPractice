#include <stdio.h>
#include <string.h>

int sLen(char str[]) {
  int length = strlen(str);
  return length;
}

int main() {
  char str[100];
  fgets(str, 100, stdin);

  int length = sLen(str);
  printf("The length: %d\n", length);

  return 0;
}
