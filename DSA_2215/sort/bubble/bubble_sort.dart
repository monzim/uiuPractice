enum SortType { Ascending, Descending }

void bubbleSort(List<int> arr, SortType sortType) {
  int n = arr.length;
  for (int i = 0; i < n - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; j++) {
      bool shouldSwap =
          (sortType == SortType.Ascending && arr[j] > arr[j + 1]) ||
              (sortType == SortType.Descending && arr[j] < arr[j + 1]);
      if (shouldSwap) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

void useme() {
  List<int> arr = [64, 25, 12, 22, 11];
  SortType sortType =
      SortType.Ascending; // Change to SortType.Descending for descending
  bubbleSort(arr, sortType);
  print("Sorted array: $arr");
}
