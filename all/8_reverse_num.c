/*
Write a program (WAP) that will reverse the digits of an input integer

Input: 12345
Output: 54321
*/

#include <stdio.h>

int main() {
  int n;
  int reversed = 0;

  printf("Enter an integer: ");
  scanf("%d", &n);

  while (n > 0) {
    int digit = n % 10;
    reversed = reversed * 10 + digit;
    n /= 10;
  }

  printf("Reversed: %d\n", reversed);

  return 0;
}

// int reverse_digits(int n) {
//   if (n == 0) return 0;
//   return (n % 10) * 10 + reverse_digits(n / 10);
// }

// int main(int argc, char *argv[]) {
//   int n;
//   printf("Enter a number : ");
//   scanf("%d", &n);

//    printf("Reverse: %d", reverse_digits(n));

//   return 0;
// }
