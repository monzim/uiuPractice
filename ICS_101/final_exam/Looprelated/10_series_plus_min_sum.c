/*
Write a program (WAP) that will give the sum of first Nth terms for the following series.
1, -2, 3, -4, 5, -6, 7, -8, 9, -10, 11, -12, 13, -14, …….
    Sample input Sample output
        2 Result: -1
        3 Result: 2
        4 Result: -2
*/

#include <stdio.h>

int main() {
  int n, i;
  int result = 0;

  printf("Enter the number of terms: ");
  scanf("%d", &n);

  for (i = 1; i <= n; i++) {
    int term;
    if (i % 2 == 0) {
      term = -i;
    } else {
      term = i;
    }
    result += term;
  }

  printf("Result: %d\n", result);

  return 0;
}
