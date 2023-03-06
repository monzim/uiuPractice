#include <stdio.h>

int main() {
  int row, col;
  scanf("%d %d", &row, &col);

  int arr[row][col];
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  printf("%d x %d matrix is:\n", row, col);
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  int rev_arr[row][col];
  for (int i = row - 1; i >= 0; i--) {
    for (int j = col - 1; j >= 0; j--) {
      rev_arr[row - i - 1][col - j - 1] = arr[i][j];
    }
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%d ", rev_arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}