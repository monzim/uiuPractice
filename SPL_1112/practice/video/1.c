#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int n = 4;
  //   scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int k;

    for (int j = 1; j <= i; j++) {
      printf("%d", j);
    }

    for (int j = 1; j < 2 * (n - i); j++) {
      printf("_");
    }

    if (i == n) {
      k = i - 1;
    } else {
      k = i;
    }

    for (int j = k; j >= 1; j--) {
      printf("%d", j);
    }

    printf("\n");
  }
  return EXIT_SUCCESS;
}
