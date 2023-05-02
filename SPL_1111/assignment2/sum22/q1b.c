#include <stdio.h>

int main() {
  int m, n, i, j, temp;
  printf("Enter the number of rows and columns of the matrix: ");
  scanf("%d %d", &m, &n);
  int matrix[m][n];
  printf("Enter the elements of the matrix:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
  // Reversing the matrix
  for (j = 0; j < n / 2; j++) {
    for (i = 0; i < m; i++) {
      temp = matrix[i][j];
      matrix[i][j] = matrix[i][n - j - 1];
      matrix[i][n - j - 1] = temp;
    }
  }
  // Printing the reversed matrix
  printf("The reversed matrix is:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}
