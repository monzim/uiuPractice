#include <stdio.h>

void selectionSort(int array[], int size) {
  // Task 1: iterate through unsorted array
  // Task 2: save min value index
  // Task 3: swich value

  for (int i = 0; i < size - 1; i++) {
    int minIndex, temp;

    minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (array[j] < array[minIndex]) {
        minIndex = j;
      }
    }

    temp = array[i];
    array[i] = array[minIndex];
    array[minIndex] = temp;
  }
}

int main() {
  int array[6] = {44, 33, 39, 1, 9999, 3};
  selectionSort(array, 6);

  for (int i = 0; i < 6; i++) {
    printf("%d, ", array[i]);
  }

  return 0;
}