/*
 WAP that will take n integer numbers into an array, and then find the maximum -
minimum among them with its index position.

Input: 5 1 2 3 4 5
Output: Maximum element: 5, Index position: 4
        Minimum element: 1, Index position: 0
 */

#include <stdio.h>

int main() {
  int n;
  printf("Enter the number of integers: ");
  scanf("%d", &n);

  int arr[n];
  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int max = arr[0], min = arr[0], max_index = 0, min_index = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
      max_index = i;
    }
    if (arr[i] < min) {
      min = arr[i];
      min_index = i;
    }
  }
  printf("Maximum element: %d, Index position: %d\n", max, max_index);
  printf("Minimum element: %d, Index position: %d\n", min, min_index);

  return 0;
}
