#include <stdio.h>
#include <stdlib.h>

long long factorial(int n) {
  if (n == 0) {
    return 1;
  }
  if (n == 1) {
    printf("%d = ", n);
    return 1;
  }
  printf("%d x ", n);
  return n * factorial(n - 1);
}

int main(int argc, char *argv[]) {

  int n = 0;
  scanf("%d", &n);
  printf("%d! = ", n);
  long long result = factorial(n);
  printf("%lld", result);
  return EXIT_SUCCESS;
}
