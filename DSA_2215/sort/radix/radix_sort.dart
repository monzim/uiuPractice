void countingSort(List<int> arr, int exp) {
  int n = arr.length;
  List<int> output = List<int>.filled(n, 0);
  List<int> count = List<int>.filled(10, 0);

  for (int i = 0; i < n; i++) {
    count[(arr[i] ~/ exp) % 10]++;
  }

  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    output[count[(arr[i] ~/ exp) % 10] - 1] = arr[i];
    count[(arr[i] ~/ exp) % 10]--;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

void radixSort(List<int> arr) {
  int maxVal = arr.reduce((a, b) => a > b ? a : b);
  for (int exp = 1; maxVal ~/ exp > 0; exp *= 10) {
    countingSort(arr, exp);
  }
}

void useMe() {
  List<int> arr = [170, 45, 75, 90, 802, 24, 2, 66];
  radixSort(arr);
  print("Sorted array: $arr");
}
