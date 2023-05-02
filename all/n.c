#include "stdio.h"
#include "stdlib.h"
#define NUM_ROWS 5
#define NUM_COLS 5

int main(int argc, char *argv[]) {
  /*
   *write a program thit will print N with number like
     1       5
     1 2     5
     1   3   5
     1     4 5
   */

  int row, col;
  // print row  in column

  for (row = 1; row <= NUM_ROWS; row++) {
    for (col = 1; col <= NUM_COLS; col++) {
//      printf("%d", col);

      if (row == 1 || row == NUM_ROWS) {
        printf("%d ", col);
      }
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
