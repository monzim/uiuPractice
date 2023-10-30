#include <stdio.h>

enum SortType { Ascending, Descending };

void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void selectionSort(int arr[], int n, enum SortType sortType) {
  int i, j, minIndex;
  for (i = 0; i < n - 1; i++) {
    minIndex = i;

    for (j = i + 1; j < n; j++) {
      if ((sortType == Ascending && arr[j] < arr[minIndex]) || (sortType == Descending && arr[j] > arr[minIndex])) {
        minIndex = j;
      }
    }

    if (minIndex != i) {
      swap(&arr[i], &arr[minIndex]);
    }
  }
}

int useMe() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);
  enum SortType sortType = Ascending;  // Change to Descending for descending

  selectionSort(arr, n, sortType);

  printf("Sorted array: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
