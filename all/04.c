#include <math.h>
#include <stdio.h>

int is_prime(int n) {
  if (n < 2)
    return 0;
  if (n == 2)
    return 1;
  if (n % 2 == 0)
    return 0;

  int max = sqrt(n);
  for (int i = 3; i <= max; i += 2) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int k;
  scanf("%d", &k);
  if (is_prime(k)) {
    printf("%d is prime", k);
  } else {
    printf("%d is not prime", k);
  }
  return 0;
}
