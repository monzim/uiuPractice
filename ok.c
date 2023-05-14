#include <stdio.h>

unsigned int factorial(unsigned int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

unsigned int fibonacci(unsigned int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}
