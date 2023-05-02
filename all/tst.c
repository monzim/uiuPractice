#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int *remove_duplicates(int arr[], int size, int *new_size) {
  int uc = 0;
  int *new_arr = malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    bool unique = true;

    for (int j = 0; j < uc; j++) {
      if (new_arr[j] == arr[i]) {
        unique = false;
        break;
      }
    }

    if (unique) {
      new_arr[uc++] = arr[i];
    }
  }

  if (uc < size) {
    new_arr = realloc(new_arr, uc * sizeof(int));
  }

  *new_size = uc;
  return new_arr;
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
}

int main(int argc, char *argv[]) {

  int array[] = {5, 1, 2, 3, 2, 2, 4, 1, 1, 5};
  int size = sizeof(array) / sizeof(array[0]);

  int newSize = 0;
  int *arr = remove_duplicates(array, size, &newSize);

  printArray(arr, newSize);
  return EXIT_SUCCESS;
}
