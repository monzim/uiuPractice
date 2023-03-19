#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int is_palindrome(int n) {
  char str[10];
  sprintf(str, "%d", n);

  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      return 0;
    }
  }
  return 1;
}

int sum_digits(int n) {
  if (n == 0) return 0;
  return (n % 10) + sum_digits(n / 10);
}

_Bool sum_of_digit_div_3(int num) {
  int sum = sum_digits(num);

  if (sum / 3 == 0) {
    return true;
  } else {
    return false;
  }
}

int main(int argc, char *argv[]) { return 0; }
