#include <stdio.h>

enum SortType { Ascending, Descending };

void insertionSort(int arr[], int n, enum SortType sortType) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && ((sortType == Ascending && arr[j] > key) || (sortType == Descending && arr[j] < key))) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }

    arr[j + 1] = key;
  }
}

int useMe() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);
  enum SortType sortType = Ascending;  // Change to Descending for descending

  insertionSort(arr, n, sortType);

  printf("Sorted array: \n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}
