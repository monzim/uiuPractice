#include <stdio.h>
#include <string.h>

/*
if(even)

1 3 8 9
2 8 9 1
1 1 3 2
9 7 1 2

if (odd)

1 6 7 9 8 1
2 8 9 1 3 4
1 1 3 2 1 6
9 7 1 2 1 6
1 2 3 4 5 1

*/

int main(int argc, char const *argv[]) {
  int row;
  scanf("%d", &row);

  int arr[row][row];
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < row; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  if (row % 2 == 0) {
    int sum = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < row; j++) {
        if (i == 0 && j != 0 && j != row - 1) {
          sum += arr[i][j];
        }

        if (i == row - 1 && j != 0 && j != row - 1) {
          sum += arr[i][j];
        }

        if (j == 0 && i != 0 && i != row - 1) {
          sum += arr[i][j];
        }

        if (j == row - 1 && i != 0 && i != row - 1) {
          sum += arr[i][j];
        }
      }
    }

    printf("Sum of all elements: %d", sum);
  } else {
    int sum = 0;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < row; j++) {
        if (i == 0 && j != 0 && j != row - 1) {
          sum += arr[i][j];
        }

        if (i == row - 1 && j != 0 && j != row - 1) {
          sum += arr[i][j];
        }

        if (j == 0 && i != 0 && i != row - 1) {
          sum += arr[i][j];
        }

        if (j == row - 1 && i != 0 && i != row - 1) {
          sum += arr[i][j];
        }

        if (i == row / 2 && j == row / 2) {
          sum += arr[i][j];
        }
      }
    }

    printf("Sum of all elements: %d", sum);
  }

  return 0;
}
