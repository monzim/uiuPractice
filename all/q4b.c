#include <stdio.h>

int main() {
  int n, arr[100];
  float odd_sum = 0, odd_count = 0;

  printf("Enter the number of integers: ");
  scanf("%d", &n);

  printf("Enter %d integers:\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("\nIndex\tValue\n");
  printf("------\t------\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\n", i, arr[i]);

    if (i % 2 == 1) {
      odd_sum += arr[i];
      odd_count++;
    }
  }

  float odd_avg = odd_sum / odd_count;
  printf("\nAverage of numbers stored in odd numbered indices: %.2f\n", odd_avg);

  return 0;
}
