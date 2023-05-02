/*
 WAP that will take n integers into an array A. Now sort them in ascending order
within that array. Finally show all elements of array A Use bubble sort
algorithm

Input:8
7 8 1 3 2 6 4 3

Output:
1 2 3 3 4 6 7 8
 * */

#include <stdio.h>

// Bubble sort function
void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int n;
  printf("Enter the number of integers: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // Call bubble sort function
  bubbleSort(arr, n);

  // Print the sorted array
  printf("Elements of array A in ascending order: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
