#include <stdio.h>
#include <stdlib.h>

int sumOfN(int n, int arr[]) {
  int sum = 0;

  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }

  return sum;
}

int main() {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int sum = sumOfN(n, arr);

  printf("Sum In Function: %d\n", sum);
  printf("Sum In Main: %d\n", sum);

  return EXIT_SUCCESS;
}
