#include <stdio.h>

int main(int argc, char *argv[]) {
  int i, j, n;
  printf("Enter the number of rows : ");
  scanf("%d", &n);
  printf("\nPyramid of * with %d rows:\n", n);
  for (i = 1; i <= n; i++) {
    printf("\n");
    for (j = 0; j < n - 1; j++) printf(" ");
    for (j = 0; j < 2 * i - 1; j++) printf("*");
  }

  return 0;
}
