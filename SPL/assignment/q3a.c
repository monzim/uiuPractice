/*
Write a complete program to print the following series up to ‘Nth’ term and also find the sum of
the series.
Sample Input N = 3
Sample Output 0, 5, 18, 39, 68, 105
Sum = 235
*/

#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i <= n; i++) {
    int term = 3 * i * (i - 1) + 1;
    printf("%d, ", term);
    sum += term;
  }
  printf("Sum = %d", sum);
  return 0;
}