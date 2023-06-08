#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
  if (n == 0) return 1;
  return n * factorial(n - 1);
}

int main(int argc, char *argv[]) {
  int k = 8;
  printf("%d", factorial(k));
  return EXIT_SUCCESS;
}
