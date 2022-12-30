/*
Write a program (WAP) that will print following series upto Nth terms.
1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31 …….

    Sample input            Sample output
    2                       1, 3
    5                       1, 3, 5, 7, 9
    11                      1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21
*/

#include <stdio.h>

int main() {
  int n;

  printf("Enter the number of terms N: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    printf("%d ", i * 2 - 1);
  }

  return 0;
}
