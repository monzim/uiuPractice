#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  printf("Hello, World!\n");
  printf("argc = %d\n", argc);

  for (int i = 0; i < argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }

  return EXIT_SUCCESS;
}
