#include <stdio.h>

void bubble_sort(int arr[], int n) {
  int temp;
  int swapped;  // flag to indicate if any swaps have been made

  // iterate through the array n times
  for (int i = 0; i < n; i++) {
    swapped = 0;  // reset the flag before each pass

    // iterate through the array from the beginning to the n-i-1-th element
    for (int j = 0; j < n - i - 1; j++) {
      // if the current element is greater than the next element, swap them
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];        // store the value of the current element in temp
        arr[j] = arr[j + 1];  // overwrite the value of the current element with the value of the next element
        arr[j + 1] = temp;    // overwrite the value of the next element with the value stored in temp

        swapped = 1;  // set the flag to indicate a swap has been made
      }
    }

    // if no swaps were made during the pass, the array is already sorted
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

  bubble_sort(array, size);

  for (int i = 0; i < size; i++) {
    printf("%d, ", array[i]);
  }

  return 0;
}
