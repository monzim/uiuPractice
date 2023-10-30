#include <stdio.h>

enum SortType { ASCENDING, DESCENDING };

void bubbleSort(int arr[], int n, enum SortType sortType) {
  int swapped;
  do {
    swapped = 0;
    for (int i = 1; i < n; i++) {
      int shouldSwap = (sortType == ASCENDING) ? (arr[i - 1] > arr[i]) : (arr[i - 1] < arr[i]);
      if (shouldSwap) {
        int temp = arr[i - 1];
        arr[i - 1] = arr[i];
        arr[i] = temp;
        swapped = 1;
      }
    }
  } while (swapped);
}

int useMe() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);
  enum SortType sortType = ASCENDING;  // Change to DESCENDING for descending

  bubbleSort(arr, n, sortType);

  printf("Sorted array: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
