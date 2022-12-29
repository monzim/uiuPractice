/*
problem: 2
 * Write a program to find the sum of the series
 * 1^2 + 3^2 + 5^2 + 7^2 + ... + n^2
 * where n is a positive integer.
*/

#include <stdio.h>

int main(void) {
  int n;
  int sum = 0;

  printf("Enter the number: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    sum += (2 * i - 1) * (2 * i - 1);
  }

  printf("sum of the series is: %d\n", sum);

  return 0;
}

// #include <stdio.h>

// int main(int argc, char *argv[]) {
//   int n = 10;
//   for (int i = 1; i <= n; i += 2) {
//     printf("%d^2 = %d\n", i, i * i);
//   }
//   return 0;
// }
