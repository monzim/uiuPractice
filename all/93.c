#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printPattern(int n) {
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
    bool unique = true;

    for (int j = 0; j < uc; j++) {
      if (new_arr[j] == arr[i]) {
        unique = false;
        break;
      }
    }

    if (unique) {
      new_arr[uc++] = arr[i];
    }
  }

  if (uc < size) {
    new_arr = realloc(new_arr, uc * sizeof(int));
  }

  *new_size = uc;
  return new_arr;
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
}

int findLastIndexOfA(char S[]) {
  int len = strlen(S);
  for (int i = len - 1; i >= 0; i--) {
    if (S[i] == 'a') {
      return i;
    }
  }

  return -1;
}

int main(int argc, char *argv[]) {
  int n;
  printf("Enter the number of rows: ");
  scanf("%d", &n);
  printPattern(n);

  int array[] = {5, 1, 2, 3, 2, 2, 4, 1, 1, 5};
  int size = sizeof(array) / sizeof(array[0]);

  int newSize = 0;
  int *arr = remove_duplicates(array, size, &newSize);

  printArray(arr, newSize);

  char S[100];

  scanf("%s", S);
  printf("%d\n", findLastIndexOfA(S));

  return EXIT_SUCCESS;
}
