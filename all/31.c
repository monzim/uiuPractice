#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int *remove_duplicates(int arr[], int size, int *new_size) {
  int i, space, rows, k = 0, count = 0, count1 = 0;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  for (i = 1; i <= rows; ++i) {
    for (space = 1; space <= rows - i; ++space) {
      printf("  ");
      ++count;
    }
    while (k != 2 * i - 1) {
      if (count <= rows - 1) {
        printf("%d ", i + k);
        ++count;
      } else {
        ++count1;
        printf("%d ", (i + k - 2 * count1));
      }
      ++k;
    }
    count1 = count = k = 0;
    printf("\n");
  }

  return EXIT_SUCCESS;
}
