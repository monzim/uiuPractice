#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}

int useMe() {
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 3;
  int index = linearSearch(arr, n, target);
  if (index != -1) {
    printf("Target %d found at index %d\n", target, index);
  } else {
    printf("Target %d not found in the array\n", target);
  }
  return 0;
}
