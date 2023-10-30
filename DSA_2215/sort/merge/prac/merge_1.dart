enum SortType { ascending, descending }

void main() {
  List<int> unsortedList = [38, 27, 43, 3, 9, 82, 10];
  // need to sort this using merge sort
  List<int> sortedList = mergeSort(unsortedList);
  print("Unsorted List: $unsortedList");
  print("Sorted List: $sortedList");
}

// merge sort function
List<int> mergeSort(List<int> list) {
  // base case
  if (list.length <= 1) {
    return list;
  }

  // calculate the middle index
  final mid = list.length ~/ 2;

  // split the list into two halves
  final List<int> left = list.sublist(0, mid);
  final List<int> right = list.sublist(mid);

  // recursively sort and merge the left and right halves
  return merge(
    mergeSort(left),
    mergeSort(right),
    sortType: SortType.descending,
  );
}

// merge function
List<int> merge(List<int> l, r, {SortType sortType = SortType.ascending}) {
  final List<int> result = [];

  int leftIndex = 0;
  int rightIndex = 0;

  // comapre
  while (leftIndex < l.length && rightIndex < r.length) {
    // check left and right
    if (sortType == SortType.ascending) {
      if (l[leftIndex] < r[rightIndex]) {
        result.add(l[leftIndex]);
        leftIndex++;
      } else {
        result.add(r[rightIndex]);
        rightIndex++;
      }
    } else {
      if (l[leftIndex] > r[rightIndex]) {
        result.add(l[leftIndex]);
        leftIndex++;
      } else {
        result.add(r[rightIndex]);
        rightIndex++;
      }
    }
  }

  // add remaining elements
  result.addAll(l.sublist(leftIndex));
  result.addAll(r.sublist(rightIndex));

  return result;
}
