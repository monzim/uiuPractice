// write a program that take 10 numbers from the user and print the reverse of each number.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

void print_pattern(int n) {
  int i, j, k = 1;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++) {
      printf("%d ", k++);
    }
    printf("\n");
  }
}

int *remove_duplicates(int arr[], int size, int *new_size) {
  int uc = 0;
  int *new_arr = malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    bool isu = true;

    for (int j = 0; j < uc; j++) {
      if (new_arr[j] == arr[i]) {
        isu = false;
        break;
      }
    }

    if (isu == true) {
      new_arr[uc++] = arr[i];
    }
  }

  if (uc < size) {
    new_arr = realloc(new_arr, uc * sizeof(int));
  }

  *new_size = uc;
  return new_arr;
}

int main(int argc, char *argv[]) {
  int array[] = {5, 1, 2, 3, 2, 2, 4, 1, 1, 5};
  int size = sizeof(array) / sizeof(array[0]);

  int new_size = 0;

  print_array(array, new_size);

  int *arr = remove_duplicates(array, size, &new_size);

  print_array(arr, new_size);

  int n;
  printf("Enter the number of rows: ");

  scanf("%d", &n);

  print_pattern(n);

  return EXIT_SUCCESS;
}
