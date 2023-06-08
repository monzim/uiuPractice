/*
 WAP that will take n integer numbers into an array, and then reverse all the
integers within that array. Finally print them all from 0 index to last valid
index.

Sample input Sample output
intput: 5 1 2 3 4 5
out: 5 4 3 2 1
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

  // Reverse the array
  for (int i = 0; i < n / 2; i++) {
    int temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;
  }

  printf("Reversed array:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
