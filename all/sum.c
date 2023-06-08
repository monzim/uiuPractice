#include <stdio.h>

float factorial(int n) {
  if (n == 0) return 1;
  return n * factorial(n - 1);
}
int power(int n, int p) {
  if (p == 0) return 1;
  return n * power(n, p - 1);
}

// float sum(int x, int n) {
//   if (n == 0) return 0;
//   return (power(x, n) / factorial(n)) + sum(x, n - 1);
// }

float sum(int x, int n) {
  if (n == 0) return 0;
  return (power(x, n) / (float)factorial(n)) + sum(x, n - 1);
}

int main(int argc, char *argv[]) {
  printf("%f ", sum(3, 5));
  //   printf("%d", power(2, 3));
  //   printf("%d", factorial(6));
  return 0;
}
