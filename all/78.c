#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char s[] = "Programming is fun";
  int i;

  for (i = 0; s[i] != '\0'; ++i)
    ;
  printf("Length of the string: %d", i);
  return 0;

  return EXIT_SUCCESS;
}
