
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int is_prime(int n) {
  if (n < 2) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;

  int max = sqrt(n);
  for (int i = 3; i <= max; i += 2) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  for (int i = 0; i < n; i++) {
    if (is_prime(arr[i])) {
      printf("%d ", arr[i]);
    }
  }

  return EXIT_SUCCESS;
}
