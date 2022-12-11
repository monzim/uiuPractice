#include <stdio.h>

void main() {
  // get the largest and second largest number from an array
  // 1. get the largest number
  // 2. get the second largest number
  // 3. print the second largest number

  // 1. get the largest number
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int count = sizeof(arr) / sizeof(arr[0]);
  int largest = arr[0];
  for (int i = 0; i < count; i++) {
    if (largest < arr[i]) {
      largest = arr[i];
    }
  }
  printf("The largest number is: %i ", largest);

  // 2. get the second largest number
  int second_largest = arr[0];
  for (int i = 0; i < count; i++) {
    if (second_largest < arr[i] && arr[i] != largest) {
      second_largest = arr[i];
    }
  }

  // 3. print the second largest number
  printf("The second largest number is: %i ", second_largest);
}