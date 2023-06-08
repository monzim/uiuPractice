#include <stdio.h>

int sum_digits(int n) {
  if (n == 0)
    return 0;
  return (n % 10) + sum_digits(n / 10);
}

int reverse_digits(int n) {
  if (n == 0)
    return 0;
  return (n % 10) * 10 + reverse_digits(n / 10);
}

int firsr_digit(int n) { return n % 10; }

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  int sum = sum_digits(n);
  int reverse = reverse_digits(n);
  int first = firsr_digit(n);

  printf("Sum: %d \n", sum);
  printf("Reverse: %d \n", reverse);
  printf("First: %d \n", first);

  if (sum == reverse && sum % 2 == 0 && first != 1) {
    printf("Yes");
  } else {
    printf("No");
  }
  return 0;
}
