#include "stdio.h"
#include "stdlib.h"

void selectionSort(int arr[], int size) {
  // iterate through unsorted array
  int temp, minIndex;
  for (int i = 0; i < size - 1; i++) {
    minIndex = i;
    // itretate through the array size - i time and get the minValue

    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    // swap value
    temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }
}

void bubbleSort(int arr[], int size) {
  // flag
  // itrate through the array n time
  int flag, temp;
  for (int i = 0; i < size; i++) {
    flag = 0;

    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // swap value and set flag
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

int main(int argc, char *argv[]) {

  int array[10] = {55, 3, 221, 35, 19, 0, 2, 1, 18, 5};
  int size = sizeof(array) / sizeof(array[0]);

  // print the array before sorting
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");

  bubbleSort(array, size);
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  return EXIT_SUCCESS;
}
