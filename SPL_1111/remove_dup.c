#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int *remove_duplicate(int arr[], int size, int *new_size) {
  int count = 0;
  int *new_arr = malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    bool is_unique = true;

    for (int j = 0; j < count; j++) {
      if (new_arr[j] == arr[i]) {
        is_unique = false;
        break;
      }
    }

    if (is_unique == true) {
      new_arr[count++] = arr[i];
    }
    if (count < size) {
      new_arr = realloc(new_arr, count * sizeof(int));
    }
  }

  *new_arr = count;
  return new_arr;
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
}

int main() {
  int array[] = {5, 1, 2, 3, 2, 2, 4, 1, 1, 5};
  int size = sizeof(array) / sizeof(array[0]);
  int newSize = 0;

  int *arr = remove_duplicate(array, size, &newSize);

  printArray(arr, newSize);
  return 0;
}
