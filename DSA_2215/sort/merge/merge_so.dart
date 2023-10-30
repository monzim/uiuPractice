// Merge Sort function
List<int> mergeSort(List<int> list) {
  // Base case: If the list has one or zero elements, it's already sorted.
  if (list.length <= 1) {
    return list;
  }

  // Calculate the middle index.
  final int mid = list.length ~/ 2;

  // Split the list into two halves.
  final List<int> left = list.sublist(0, mid);
  final List<int> right = list.sublist(mid);

  // Recursively sort and merge the left and right halves.
  return merge(mergeSort(left), mergeSort(right));
}

// Merge function to combine two sorted lists into one sorted list.
List<int> merge(List<int> left, List<int> right) {
  final List<int> result = [];
  int i = 0; // Index for the left list.
  int j = 0; // Index for the right list;

  // Compare elements from the left and right lists and add the smaller one to the result.
  while (i < left.length && j < right.length) {
    if (left[i] < right[j]) {
      result.add(left[i]);
      i++;
    } else {
      result.add(right[j]);
      j++;
    }
  }

  // Add any remaining elements from the left and right lists to the result.
  result.addAll(left.sublist(i));
  result.addAll(right.sublist(j));

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
