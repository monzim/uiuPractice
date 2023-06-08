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
  int uc = 0;
  int *new_arr = malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    bool isu = true;

    for (int j = 0; j < uc; j++) {
      if (new_arr[j] == arr[i]) {
        isu = false;
        break;
      }
    }

    if (isu == true) {
      new_arr[uc++] = arr[i];
    }
  }

  if (uc < size) {
    new_arr = realloc(new_arr, uc * sizeof(int));
  }

  *new_size = uc;
  return new_arr;
}

int main(int argc, char *argv[]) {
  int num = 0;

  int i, j, rows;
  printf("Enter the number of rows: ");
  scanf("%d", &rows);
  for (i = 1; i <= rows; ++i) {
    for (j = 1; j <= i; ++j) {
      printf("* ");
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
