#include <stdio.h>

// recursion is a function that calls itself until it reaches a base case
// base case is a condition that stops the recursion
// recursion is a way to solve a problem by breaking it down into smaller

// simple recursion
int factorial(int n) {
  if (n == 0) return 1;
  printf("%d ", n);
  return n * factorial(n - 1);
}

int power(int x, int n) {
  if (n == 0) return 1;
  return x * (power(x, n - 1));
}

int main(int argc, char *argv[]) {
  int k;
  k = power(2, 3);
  printf("%d", k);

  return 0;
}
