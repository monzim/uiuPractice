#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int n;
  printf("odd n: ");
  scanf("%d", &n);

  if (n % 2 == 0) {
    printf("need an odd.\n");
    return 0;
  }

  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (i == (n + 1) / 2 || j == (n + 1) / 2) {
        printf("* ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }

   return EXIT_SUCCESS;
}
