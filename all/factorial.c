#include <stdio.h>

int factorial(int n) {
  if (n == 0) return 1;
  //   printf("%d * ", n, n - 1);
  return n * factorial(n - 1);
}

int main(int argc, char *argv[]) {
  int k = 8;
  printf("%d", factorial(k));
  return 0;
}
