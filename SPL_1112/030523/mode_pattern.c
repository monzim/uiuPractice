#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int num;
  scanf("%d", &num);
  int mode = 1;

  int row, col;
  int count = 1;
  for (row = 1; row <= num; row++) {
    for (col = 1; col <= num - row; col++) {
      printf("  ");
    }
    for (col = row; col >= 1; col--) {

      printf("%d ", count);

      if (mode == 1) {
        count++;
        if (count == num)
          mode = -mode;
      } else {
        count--;
        if (count == 1)
          mode = -mode;
      }
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
