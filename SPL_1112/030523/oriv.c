
#include <stdio.h>

int main()

{
  int num;
  scanf("%d", &num);

  int row, col;
  for (row = 1; row <= num; row++) {
    for (col = 1; col <= num - row; col++) {
      printf("  ");
    }
    for (col = row; col >= 1; col--) {
      printf("%d ", col);
    }
    for (col = 2; col <= row; col++) {
      printf("%d ", col);
    }
    printf("\n");
  }

  return 0;
}
