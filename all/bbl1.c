// Write the steps of bubble sort
/*
1. Iterate through the array n times
2. Iterate through the array from the beginning to the n-i-1-th element
3. If the current element is greater than the next element, swap them
4. If no swaps were made during the pass, the array is already sorted

*/

#include <stdio.h>

void bubbleSort(int array[], int size) {
  int temp;
  int swapped;  // Flag to indicate sort done

  // 1. Iterate through the array n times
  for (int i = 0; i < size; i++) {
    //  2. Iterate through the array from the beginning to the n-i-1-th element
    swapped = 0;  // reset swap val
    for (int j = 0; j < size - i - 1; j++) {
      //  3. If the current element is greater than the next element, swap them
      if (array[j] > array[j + 1]) {
        // Swap
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;

        swapped = 1;
      }
    }

    //  4. If no swaps were made during the pass, the array is already sorted
    if (swapped == 0) {
      break;
    }
  }
}

int main(int argc, char const *argv[]) {
  int array[] = {3, 5, 1, 0, 44, 2, 34, 10, 8};
  int size = sizeof(array) / sizeof(array[0]);

  for (int i = 0; i < size; i++) {
    printf("%d, ", array[i]);
  }

  printf("\n");

  bubbleSort(array, size);

  for (int i = 0; i < size; i++) {
    printf("%d, ", array[i]);
  }
  return 0;
}
