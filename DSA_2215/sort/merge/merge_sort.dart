// Function to perform merge sort
List<int> mergeSort(List<int> list) {
  // Base case: If the list has one or zero elements, it's already sorted.
  if (list.length <= 1) {
    return list;
  }

  // Calculate the middle index of the list.
  final int mid = list.length ~/ 2;
  print("mid: $mid");

  // Recursively sort the left and right halves of the list.
  final List<int> left = mergeSort(list.sublist(0, mid));
  print("left: $left");
  final List<int> right = mergeSort(list.sublist(mid));
  print("right: $right");

  // Merge the sorted left and right halves.
  return merge(left, right);
}

// Function to merge two sorted lists into one sorted list.
List<int> merge(List<int> left, List<int> right) {
  final List<int> result = []; // The sorted result.

  int leftIndex = 0; // The index of the first unprocessed element in left.
  int rightIndex = 0; // The index of the first unprocessed element in right.

  // Compare elements from both lists and add the smaller element to the result.
  while (leftIndex < left.length && rightIndex < right.length) {
    if (left[leftIndex] < right[rightIndex]) {
      result.add(left[leftIndex]);
      leftIndex++;
    } else {
      result.add(right[rightIndex]);
      rightIndex++;
    }
  }

  // Add any remaining elements from the left and right lists to the result.
  result.addAll(left.sublist(leftIndex));
  result.addAll(right.sublist(rightIndex));

  return result;
}

void main() {
  // Example unsorted list to be sorted using merge sort.
  List<int> unsortedList = [38, 27, 43, 3, 9, 82, 10];

  // Call the mergeSort function to sort the list.
  List<int> sortedList = mergeSort(unsortedList);

  // Print the unsorted and sorted lists for demonstration.
  print("Unsorted List: $unsortedList");
  print("Sorted List: $sortedList");
}
