/*
Write a program (WAP) that will find nCr where n >= r; n and r are integers.
    Sample input Sample output
        5 2         10
        10 3        120
        7 7         1
        6 1         6
 */

#include <stdio.h>

long long factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

int main() {
  int n, r;
  long long n_factorial, r_factorial, n_minus_r_factorial;

  printf("Enter the value of n: ");
  scanf("%d", &n);
  printf("Enter the value of r: ");
  scanf("%d", &r);

  if (n < r) {
    printf("Error: n must be greater than or equal to r\n");
    return 1;
  }

  n_factorial = factorial(n);
  r_factorial = factorial(r);
  n_minus_r_factorial = factorial(n - r);

  printf("%dC%d = %lld\n", n, r, n_factorial / (r_factorial * n_minus_r_factorial));

  return 0;
}
