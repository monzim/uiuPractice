#include <stdio.h>

int sum_digits(int n) {
  if (n == 0) return 0;
  return (n % 10) + sum_digits(n / 10);
}

int reverse_digits(int n) {
  if (n == 0) return 0;
  return (n % 10) * 10 + reverse_digits(n / 10);
}

int main(int argc, char *argv[]) {
  int n;
  printf("Enter a number : ");
  scanf("%d", &n);

  printf("Sum: %d", sum_digits(n));
  printf("Reverse: %d", reverse_digits(n));

  return 0;
}
