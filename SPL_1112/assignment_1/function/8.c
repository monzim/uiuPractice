#include <stdio.h>
#include <stdlib.h>

void printMe(int arr[], int n) {
  for (int i = n - 1; i >= 0; i--) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("rev");
  printMe(arr, n);

  return EXIT_SUCCESS;
}
