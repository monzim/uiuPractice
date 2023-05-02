/*
Manually trace the following code for ‘rows = 3’. Show changes of all the variables in each
step.
 int i, space, rows, k = 0, count = 0, count1 = 0;
 for (i = 1; i <= rows; ++i) {
 for (space = 1; space <= rows - i; ++space) {
 printf(" ");
 ++count;
 }
 while (k != 2 * i - 1) {
 if (count <= rows - 1) {
 printf("%d ", i + k);
 ++count;
 } else {
 ++count1;
 printf("%d ", (i + k - 2 * count1));
 }
 ++k;
 }
 count1 = count = k = 0;
 printf("\n");
 }
*/

#include <stdio.h>
int main() {
  int rows;
  scanf("%d", &rows);
  int i, space, k = 0, count = 0, count1 = 0;
  for (i = 1; i <= rows; ++i) {
    for (space = 1; space <= rows - i; ++space) {
      printf(" ");
      ++count;
    }
    while (k != 2 * i - 1) {
      if (count <= rows - 1) {
        printf("%d ", i + k);
        ++count;
      } else {
        ++count1;
        printf("%d ", (i + k - 2 * count1));
      }
      ++k;
    }
    count1 = count = k = 0;
    printf("\n");
  }
  return 0;
}