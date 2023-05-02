/*
WAP that will take n integer numbers into an array, and then print all the integers into
reverse order (from the last valid index to index 0).
Sample input Sample output
intput: 5 1 2 3 4 5
out: 5 4 3 2 1
intput: 6 2 8 3 9 0 1
output: 1 0 9 3 8 2 

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

  printf("Integers in reverse order:\n");
  for (int i = n - 1; i >= 0; i--) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
