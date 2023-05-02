// Write a program (WAP) that will take N numbers as inputs and compute their
// average. (Restriction: Without using any array)

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int i, n, sum = 0, num;
  float avg;

  printf("Enter the value of N: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &num);
    sum += num;
  }

  avg = (float)sum / n;

  printf("Average = %.2f", avg);

  return EXIT_SUCCESS;
}
