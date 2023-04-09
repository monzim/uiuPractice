#include <stdio.h>

void fibonacci(int n) {
  if (n == 0 || n == 1) {
    printf("fibonacci(%d) = 0 \r \n", n);
    return;
  }
  fibonacci(n - 1);
  int k = n - 1 + n + 2;
  printf("fibonacci(%d) = %d \r \n", n, k);
}

int main(int argc, char *argv[]) {
  int k;
  fibonacci(5);
  return 0;
}
