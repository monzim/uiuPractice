/*
WAP that will take (n x n) integer inputs into a square matrix of dimension n (where n must
be an odd number). Then calculate sum of the integers at first row, last row and two
diagonals without overlap. Please see the sample input-output.
*/

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

  int sum = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (i == 0 || i == row - 1 || i == j || i + j == row - 1) {
        sum += arr[i][j];
      }
    }
  }

  printf("%d", sum);

  return 0;
}