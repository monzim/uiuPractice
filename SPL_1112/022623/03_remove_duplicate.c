#include <stdio.h>

void removeDuplicates(int A[], int n, int unique[], int *size) {
  for (int i = 0; i < n; i++) {
    int isDuplicate = 0;
    for (int j = 0; j < *size; j++) {
      if (A[i] == unique[j]) {
        isDuplicate = 1;
        break;
      }
    }

    if (!isDuplicate) {
      unique[*size] = A[i];
      (*size)++;
    }
  }
}

int main() {
  int n;
  printf("Enter the number of integers: ");
  scanf("%d", &n);

  int A[n], unique[n], size = 0;
  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  removeDuplicates(A, n, unique, &size);

  printf("Elements of array A after removing duplicates: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", unique[i]);
  }
  printf("\n");

  return 0;
}
