#include <stdio.h>

void fibonacci(int n) {
  static int a = 0, b = 1, c;
  if (n > 0) {
    c = a + b;
    a = b;
    b = c;
    printf("%d, ", a);
    fibonacci(n - 1);
  }
}

int main(int argc, char *argv[]) {
  int k;
  fibonacci(10);
  return 0;
}
