#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[], int size) {
  int temp, min_index;
  for (int i = 0; i < size - 1; i++) {
    min_index = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }

    temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n\n");
}

int main(int argc, char *argv[]) {
  int size = 5;
  scanf("%d", &size);
  int arr[size];
  srand(time(NULL));

  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 100000 + 1;
  }

  printf("Before sorting: ");
  printArray(arr, size);

  clock_t start_time = clock();
  selection_sort(arr, size);
  clock_t end_time = clock();
  printf("After sorting: ");
  printArray(arr, size);

  double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  printf("Time taken: %f seconds \n", time_taken);

  return EXIT_SUCCESS;
}
