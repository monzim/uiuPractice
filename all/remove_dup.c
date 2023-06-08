#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int *remove_duplicate(int arr[], int size, int *newSize) {
  int uc = 0;
  int *new_array = malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    bool is_unique = true;

    for (int j = 0; j < uc; j++) {
      if (new_array[j] == arr[i]) {
        is_unique = false;
        break;
      }
    }

    if (is_unique == true) {
      new_array[uc++] = arr[i];
    }
  }

  if (uc < size) {
    new_array = realloc(new_array, uc * sizeof(int));
  }

  *newSize = uc;
  return new_array;
}

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  int array[] = {1, 2, 3, 4, 4, 4};
  int size = sizeof(array) / sizeof(array[0]);

  int newSize = 0;

  int *arr = remove_duplicate(array, size, &newSize);

  print_array(arr, newSize);

  return 0;
}
