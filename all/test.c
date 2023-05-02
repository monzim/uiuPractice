#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int *create_random_array(int length, int max_value, int num_duplicates) {
  int *array = (int *)malloc(length * sizeof(int));
  srand(time(NULL));  // Seed the random number generator with current time

  // Fill the array with random values
  for (int i = 0; i < length; i++) {
    array[i] = rand() % (max_value + 1);
  }

  // Create duplicates
  for (int i = 0; i < num_duplicates; i++) {
    int index = rand() % length;
    int value = array[index];
    int duplicate_index = rand() % length;
    array[duplicate_index] = value;
  }

  return array;
}

int *remove_duplicatesW(int arr[], int size, int *new_size) {
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

int main() {
  int array[] = {44,  33,   41,     53,  66,  44, 90, 7, 2,  2,   24, 4,  1,  56, 3, 92929, 11,  222, 32323,
                 414, 1424, 124124, 241, 124, 12, 41, 1, 24, 124, 12, 41, 24, 1,  4, 4,     124, 21};
  int size = sizeof(array) / sizeof(array[0]);
  //   int length = 300;
  //   int max_value = 10000;
  //   int num_duplicates = 200;
  //   int *array = create_random_array(length, max_value, num_duplicates);

  clock_t startTime = clock();
  int newSize = 0;

  srand(time(NULL));
  int *arr = remove_duplicates(array, size, &newSize);
  clock_t endTime = clock();
  double timeNeed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

  printf("Time take: %f sec", timeNeed);
  for (int i = 0; i < 5; i++) {
    printf("%d, ", array[i]);
  }

  return 0;
}