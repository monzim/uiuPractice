#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int size) {
  int temp, flag;
  for (int i = 0; i < size; i++) {
    flag = 0;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        flag = 1;
      }
    }

    if (flag == 0) break;
  }
}

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  bubble_sort(arr, n);

  print_array(arr, n);

  return EXIT_SUCCESS;
}
