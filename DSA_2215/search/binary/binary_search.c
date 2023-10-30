#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

void useMe() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 3;
  int index = binarySearch(arr, n, target);
  if (index != -1) {
    printf("Target %d found at index %d\n", target, index);
  } else {
    printf("Target %d not found in the array\n", target);
  }
}

int main() {
  useMe();
  return 0;
}
