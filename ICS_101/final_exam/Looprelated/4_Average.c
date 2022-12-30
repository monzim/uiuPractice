/*
Write a program (WAP) that will take N numbers as inputs and compute their average.
(Restriction: Without using any array)
*/

#include <stdio.h>

int main() {
  int n;
  double sum = 0;

  printf("Enter the number of numbers N: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    double x;
    printf("Enter number %d: ", i);
    scanf("%lf", &x);
    sum += x;
  }

  printf("Average: %.2lf\n", sum / n);

  return 0;
}
