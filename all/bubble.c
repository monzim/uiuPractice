#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size) {
  int temp;
  bool swapped;

  for (int i = 0; i < size; i++) {
    swapped = false;

    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
  }
}

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {
  int arr[] = {1, 4, 2, 1, 5, 0};
  int size = sizeof(arr) / sizeof(arr[0]);

  bubbleSort(arr, size);

  print_array(arr, size);
  return 0;
}
