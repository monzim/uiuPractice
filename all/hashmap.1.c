#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *remove_duplicates(int arr[], int size, int *new_size) {
  int unique_count = 0;
  int *new_arr = malloc(size * sizeof(int));
  bool *hash_table = calloc(100000, sizeof(bool));  // assuming the maximum value in the array is 100000

  for (int i = 0; i < size; i++) {
    if (!hash_table[arr[i]]) {
      hash_table[arr[i]] = true;
      new_arr[unique_count++] = arr[i];
    }
  }

  if (unique_count < size) {
    new_arr = realloc(new_arr, unique_count * sizeof(int));
  }

  *new_size = unique_count;

  free(hash_table);

  return new_arr;
}

int *remove_duplicate(int arr[], int size, int *new_size) {
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

int *removeDuplicate(int arr[], int size, int *new_size) {
  int unique_count = 0;
  int *new_arr = malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    bool is_uniq = true;

    for (int j = 0; j < unique_count; j++) {
      if (new_arr[j] == arr[i]) {
        is_uniq = false;
        break;
      }
    }

    if (is_uniq) {
      new_arr[unique_count++] = arr[i];
    }
  }

  if (unique_count < size) {
    new_arr = realloc(new_arr, unique_count * sizeof(int));
  }

  *new_size = unique_count;
  return new_arr;
}

int *removeDup(int arr[], int size, int *new_size) {
  int *new_arr = malloc(size * sizeof(int));
  int unique_c = 0;

  for (int i = 0; i < size; i++) {
    bool is_uniq = true;
    for (int j = 0; j < unique_c; j++) {
      if (arr[i] == new_arr[j]) {
        is_uniq = false;
        break;
      }
    }

    if (is_uniq) {
      new_arr[unique_c++] = arr[i];
    }
  }

  if (unique_c < size) {
    new_arr = realloc(new_arr, unique_c + sizeof(int));
  }

  *new_size = unique_c;
  return new_arr;
}

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int array[] = {1, 2, 3, 2, 2, 4, 1, 1, 5};
  int size = sizeof(array) / sizeof(array[0]);
  int newSize = 0;

  int *newOl = remove_duplicates(array, size, &newSize);
  print_array(newOl, newSize);

  return EXIT_SUCCESS;
}
