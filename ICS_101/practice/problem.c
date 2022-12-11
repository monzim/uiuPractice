#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
  // Compare two integers and return the difference
  return (*(int *)a - *(int *)b);
}

int main() {
  // Initialize the array with 10 million elements
  int array[10000000];

  // Sort the array in ascending order
  qsort(array, 10000000, sizeof(int), compare);

  // The largest number is the last element of the sorted array
  int largest = array[10000000 - 1];

  // The second largest number is the second to last element of the sorted array
  int secondLargest = array[10000000 - 2];

  // The lowest number is the first element of the sorted array
  int lowest = array[0];

  // Print the results
  printf("Largest number: %d\n", largest);
  printf("Second largest number: %d\n", secondLargest);
  printf("Lowest number: %d\n", lowest);

  return 0;
}
