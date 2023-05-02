/*
WAP that will determine whether a number is prime or not.
Sample input Sample output
    1 Not prime
    2 Prime
    11 Prime
    39 Not prime
    101 Prime
*/

#include <math.h>
#include <stdio.h>

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

int main() {
  // Test
  printf("%d\n", is_prime(2));  // Output: 1
  printf("%d\n", is_prime(3));  // Output: 1
  printf("%d\n", is_prime(4));  // Output: 0
  printf("%d\n", is_prime(5));  // Output: 1
  printf("%d\n", is_prime(6));  // Output: 0
  return 0;
}
