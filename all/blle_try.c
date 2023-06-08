#include <stdio.h>

void bubble_sort(int arr[], int size) {
  int temp, swapped;

  // Iterrate through the array n time
  for (int i = 0; i < size; i++) {
    // Reset swapped value
    swapped = 0;

    // Iterrate through the array n - i -1 time to compare the 0 and 0+1 value
    for (int j = 0; j < size - i - 1; j++) {
      // check and swap
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        swapped = 1;
      }
    }

    // Check is sort done
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
