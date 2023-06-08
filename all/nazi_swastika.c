#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  int row, col;
  scanf("%d %d", &row, &col);

  int arr[row][col];
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  printf("%d x %d matrix :\n", row, col);
  int sum = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      // Middle row
      if (i == row / 2) {
        if (j == row - 1 || j == row / 2 || (i == 0 && j < row / 2)) {
          // printf("%d ", arr[i][j]);
          // sum += arr[i][j];
        }

        // Last row
        if (j == row - 1) {
          // printf("%d ", arr[i][j]);
        }

        // Middle column
        if (j == col / 2) {
          printf("%d ", arr[i][j]);
          sum += arr[i][j];
        }

        // Bottom left corner
        if (j == 0 && i == row - 1) {
          printf("%d ", arr[i][j]);
          sum += arr[i][j];
        }

        // Bottom right corner
        if (j == col - 1 && i == row - 1) {
          printf("%d ", arr[i][j]);
          sum += arr[i][j];
        }
      }
      printf("\n");
    }

    printf("Sum of all elements: %d", sum);

    // print the nazi swastika pattern
    //   for (int i = 0; i < row; i++) {
    //     for (int j = 0; j < col; j++) {
    //       if (i == 0 || i == row - 1) {
    //         printf("* ");
    //       } else if (j == 0 || j == col - 1) {
    //         printf("* ");
    //       } else if (i == j) {
    //         printf("* ");
    //       } else if (i + j == row - 1) {
    //         printf("* ");
    //       } else {
    //         printf("  ");
    //       }
    //     }
    //     printf("\n");
    //   }

    return 0;
  }
}