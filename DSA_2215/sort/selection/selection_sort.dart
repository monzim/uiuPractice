enum SortType { Ascending, Descending }

void selectionSort(List<int> arr, SortType sortType) {
  int n = arr.length;
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;

    for (int j = i + 1; j < n; j++) {
      if ((sortType == SortType.Ascending && arr[j] < arr[minIndex]) ||
          (sortType == SortType.Descending && arr[j] > arr[minIndex])) {
        minIndex = j;
      }
    }

    if (minIndex != i) {
      int temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
    }
  }
}

void useMe() {
  List<int> arr = [64, 25, 12, 22, 11];
  SortType sortType =
      SortType.Ascending; // Change to SortType.Descending for descending
  selectionSort(arr, sortType);
  print("Sorted array: $arr");
}
