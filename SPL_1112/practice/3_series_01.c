// Write a program (WAP) that will print following series upto Nth terms.
//  1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, ……

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    printf("%d", i % 2);
    if (i != n)
      printf(", ");
  }

  return EXIT_SUCCESS;
}
