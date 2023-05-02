#include <stdio.h>
#include <stdlib.h>

void selection_sort(int arr[], int size) {
  int temp, minIndex;

  for (int i = 0; i < size - 1; i++) {
    minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[minIndex]) {
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
  int size = 5;
  int arr[size];

  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 10000 + 1;
  }

  print_array(arr, size);
  selection_sort(arr, size);
  print_array(arr, size);

  return EXIT_SUCCESS;
}
