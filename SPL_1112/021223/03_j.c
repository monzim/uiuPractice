#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int k = 0;
  int sum = 0;
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    int term = pow(i, 2) * (i + 1);
    printf("%d^2 x %d ", i, i + 1);
    sum += term;
  }

  printf("= %d\n", sum);

  return EXIT_SUCCESS;
}
