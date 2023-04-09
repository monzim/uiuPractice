#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int is_prime(int n) {
  if (n < 2) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;

  int max = sqrt(n);
  for (int i = 3; i <= max; i += 2) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int genPrime(int n) {
  int count = 0, num = 2;

  while (count < n) {
    if (is_prime(num)) {
      count++;
    }

    if (count == n) {
      break;
    }

    num++;
  }

  return num;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  printf("%dth Prime: %d", n, genPrime(n));

  return EXIT_SUCCESS;
}
