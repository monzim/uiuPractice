// Write a program (WAP) that will print following series upto Nth terms.
// 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31 …

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int n;
  scanf("%d", &n);

  for (int i = 0; i <= n; ++i) {
    printf("%d", 2 * i + 1);
    if (i != n)
      printf(", ");
  }

  return EXIT_SUCCESS;
}
