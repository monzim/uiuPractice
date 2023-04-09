#include <stdio.h>
#include <stdlib.h>

void eve(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      printf("%d ", arr[i]);
    }
  }
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  eve(arr, n);

  return EXIT_SUCCESS;
}
