#include <stdio.h>

int main() {
  int n;
  printf("Enter an odd integer n: ");
  scanf("%d", &n);
  if (n % 2 == 0) {
    printf("Please enter an odd integer.\n");
    return 0;
  }
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (i == (n + 1) / 2 || j == (n + 1) / 2) {
        printf("H ");
      } else {
        printf("  ");
      }
    }
    printf("\n");
  }
  return 0;
}
