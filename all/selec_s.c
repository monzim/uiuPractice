#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int size) {
  int minIndex, temp;

  for (int i = 0; i < size - 1; i++) {
    minIndex = i;

    for (int j = i + 1; j < size; j++) {
      if (arr[i] > arr[j]) {
        minIndex = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
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

  selectionSort(arr, size);
  print_array(arr, size);

  return 0;
}
