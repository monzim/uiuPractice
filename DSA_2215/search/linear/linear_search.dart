int linearSearch(List<int> arr, int target) {
  for (int i = 0; i < arr.length; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}

void useMe() {
  List<int> arr = [1, 2, 3, 4, 5];
  int target = 3;
  int index = linearSearch(arr, target);
  if (index != -1) {
    print("Target $target found at index $index");
  } else {
    print("Target $target not found in the array");
  }
}
