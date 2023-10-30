// // Example use case
// final unsortedList = [38, 27, 43, 3, 9, 82, 10];
// final sortedList = mergeSort(unsortedList);
// print("Unsorted List: $unsortedList");
// print("Sorted List: $sortedList");

enum SortOrder { ascending, descending }

List<int> mergeSort(List<int> list) {
  if (list.length <= 1) return list;
  final mid = list.length ~/ 2;
  return merge(
    mergeSort(list.sublist(0, mid)),
    mergeSort(list.sublist(mid)),
    sortOrder: SortOrder.descending,
  );
}

List<int> merge(List<int> left, List<int> right,
    {SortOrder sortOrder = SortOrder.ascending}) {
  final result = <int>[];
  int i = 0, j = 0;

  while (i < left.length && j < right.length) {
    if (sortOrder == SortOrder.ascending) {
      result.add(left[i] < right[j] ? left[i++] : right[j++]);
    } else {
      result.add(left[i] > right[j] ? left[i++] : right[j++]);
    }
  }
  return [...result, ...left.sublist(i), ...right.sublist(j)];
}

void main() {
  final unsortedList = [38, 27, 43, 3, 9, 82, 10];
  final sortedList = mergeSort(unsortedList);
  print("Unsorted List: $unsortedList");
  print("Sorted List: $sortedList");
}
