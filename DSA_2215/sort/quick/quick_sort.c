#include <stdio.h>

enum SortType { Ascending, Descending };

void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int low, int high, enum SortType sortType) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if ((sortType == Ascending && arr[j] < pivot) || (sortType == Descending && arr[j] > pivot)) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high, enum SortType sortType) {
  if (low < high) {
    int pi = partition(arr, low, high, sortType);

    quickSort(arr, low, pi - 1, sortType);
    quickSort(arr, pi + 1, high, sortType);
  }
}

int useMe() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);
  enum SortType sortType = Ascending;  // Change to Descending for descending

  quickSort(arr, 0, n - 1, sortType);

  printf("Sorted array: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
