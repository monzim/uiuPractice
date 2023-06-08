#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int *remove_duplicates(int arr[], int size, int *new_size) {
  int unique_count = 0;
  int *new_arr = malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    bool is_unique = true;

    for (int j = 0; j < unique_count; j++) {
      if (arr[i] == new_arr[j]) {
        is_unique = false;
        break;
      }
    }

    if (is_unique) {
      new_arr[unique_count++] = arr[i];
    }
  }

  if (unique_count < size) {
    new_arr = realloc(new_arr, unique_count * sizeof(int));
  }

  *new_size = unique_count;

  return new_arr;
}

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int main() {
  int array[] = {5, 1, 2, 3, 2, 2, 4, 1, 1, 5};
  int size = sizeof(array) / sizeof(array[0]);
  int newSize = 0;

  int *newOl = remove_duplicates(array, size, &newSize);
  print_array(newOl, newSize);

  return EXIT_SUCCESS;
}