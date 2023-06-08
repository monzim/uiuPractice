// Write a program (WAP) that will print following series upto Nth terms.
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14
#include <stdio.h>
#include <stdlib.h>

int main() {

  int i;
  scanf("%d", &i);
  for (int j = 1; j <= i; j++) {
    printf("%d", j);
    if (j != i)
      printf(", ");
  }

  return EXIT_SUCCESS;
}
