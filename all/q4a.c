#include <stdio.h>

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

#include <stdio.h>

int main() {
  int F[6] = {0};
  int i, n;
  n = 3;
  for (i = 0; i < 6; i++) {
    F[i] = n + i;
    if (F[i] % 2 == 0) {
      F[i] *= 2;
    }
  }

  print_array(F, 6);

  return 0;
}
