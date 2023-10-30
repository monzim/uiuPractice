enum SortType { Ascending, Descending }

void insertionSort(List<int> arr, SortType sortType) {
  for (int i = 1; i < arr.length; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 &&
        (sortType == SortType.Ascending && arr[j] > key ||
            sortType == SortType.Descending && arr[j] < key)) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }

    arr[j + 1] = key;
  }
}

void useMe() {
  List<int> arr = [64, 25, 12, 22, 11];
  SortType sortType =
      SortType.Ascending; // Change to SortType.Descending for descending
  insertionSort(arr, sortType);
  print("Sorted array: $arr");
}
