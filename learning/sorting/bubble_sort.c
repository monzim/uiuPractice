#include "stdlib.h"
#include <stdio.h>
#include <time.h>

void bubble_sort(int arr[], int size) {
  int flag, temp;
  for (int i = 0; i < size - 1; i++) {
    flag = 0;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        flag = 1;
      }
    }

    if (flag == 0) {
      break;
    }
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
  bubble_sort(arr, size);
  clock_t end_time = clock();
  printf("After sorting: ");
  printArray(arr, size);

  double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  printf("Time taken: %f seconds \n", time_taken);

  return EXIT_SUCCESS;
}
