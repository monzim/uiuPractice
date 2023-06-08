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

int main() {
  printf("Wrocle");

  int array[100], position, c, n;
  printf("\n\nEnter number of elements in array:");
  scanf("%d", &n);

  printf("\n\nEnter %d elements\n", n);
  for (c = 0; c < n; c++) scanf("%d", &array[c]);

  printf("\n\nEnter the location where you want to delete element from:  ");
  scanf("%d", &position);

  if (position >= n + 1)
    printf("\n\nDeletion not possible\n\n");
  else
    // updating the locations with next elements
    for (c = position - 1; c < n - 1; c++) array[c] = array[c + 1];

  printf("\n\nResultant array is: ");
  /*
      the array size gets reduced by 1
      after deletion of the element
  */
  for (c = 0; c < n - 1; c++) printf("%d  ", array[c]);

  printf("\n\n\t\t\tCoding is Fun !\n\n\n");
  return 0;
}