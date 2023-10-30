enum SortType { Ascending, Descending }

void quickSort(List<int> arr, SortType sortType) {
  if (arr.length < 2) return;
  int pivot = arr[arr.length ~/ 2];
  List<int> left = [];
  List<int> right = [];

  for (int i in arr) {
    if (i < pivot) {
      left.add(i);
    } else if (i > pivot) {
      right.add(i);
    }
  }

  quickSort(left, sortType);
  quickSort(right, sortType);

  arr.clear();
  arr.addAll(sortType == SortType.Ascending ? left : right);
  arr.add(pivot);
  arr.addAll(sortType == SortType.Ascending ? right : left);
}

void useMe() {
  List<int> arr = [64, 25, 12, 22, 11];
  SortType sortType =
      SortType.Ascending; // Change to SortType.Descending for descending
  quickSort(arr, sortType);
  print("Sorted array: $arr");
}
