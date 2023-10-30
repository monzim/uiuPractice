int binarySearch(List<int> arr, int target) {
  int low = 0;
  int high = arr.length - 1;
  while (low <= high) {
    int mid = low + ((high - low) ~/ 2);
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

void useMe() {
  List<int> arr = [1, 2, 3, 4, 5];
  int target = 3;
  int index = binarySearch(arr, target);
  if (index != -1) {
    print("Target $target found at index $index");
  } else {
    print("Target $target not found in the array");
  }
}

void main() {
  useMe();
}
