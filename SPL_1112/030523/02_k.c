#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int n = 5;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      printf(" ");
    }
    for (int k = 0; k < 2 * i + 1; k++) {
      printf("*");
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
