#include <stdio.h>
#include <stdlib.h>

void printMe(char c) { printf("Value received from main: %c", c); }

int main(int argc, char *argv[]) {
  char c;
  scanf("%c", &c);

  printMe(c);
  return EXIT_SUCCESS;
}
