#include <stdio.h>
#include <stdlib.h>

int min(int arr[], int n) {
  int min = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  int arr[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("%d", min(arr, n));

  return EXIT_SUCCESS;
}
