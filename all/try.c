#include <stdio.h>

int main() {
  int n;
  printf("integers: ");
  scanf("%d", &n);

  int A[n], unique[n], size = 0;
  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  // Remove duplicates

  printf("removing duplicates: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", unique[i]);
  }
  printf("\n");

  return 0;
}
