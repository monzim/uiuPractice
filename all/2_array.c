#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int pos;
  printf("Enter the position of the element to be deleted: ");
  scanf("%d", &pos);

  if (pos < 0 || pos >= n) {
    printf("Invalid position");
    return EXIT_FAILURE;
  }

  for (int j = pos; j < n - 1; j++) {
    arr[j] = arr[j + 1];
  }

  n--;

  printf("The array after deletion is: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return EXIT_SUCCESS;
}
