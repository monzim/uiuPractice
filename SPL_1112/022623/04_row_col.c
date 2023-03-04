#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[]) {

  // row and column
  int row, col;
  scanf("%d %d", &row, &col);
  //
  //  for (int i = 0; i < row; i++) {
  //    for (int j = 0; j < col; j++) {
  //      printf("%d ", i * col + j);
  //    }
  //    printf("\n");
  //  }
  //
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (i == j || i + j == row - 1) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
