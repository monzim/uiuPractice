#include <stdio.h>
#include <stdlib.h>

int* mulArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    arr[i] *= 2;
  }
  return arr;
}

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char* argv[]) {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int* result = mulArray(arr, n);

  print_array(result, n);

   return EXIT_SUCCESS;
}
