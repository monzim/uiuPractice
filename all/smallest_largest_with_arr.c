#include <stdio.h>

int main(int argc, char *argv[]) {
  int n;

  printf("Enter the number count: ");
  scanf("%i", &n);

  float arr[n];

  for (int i = 0; i < n; i++) {
    printf("Enter element %i: ", i + 1);
    scanf("%f", &arr[i]);
  }

  int count = sizeof(arr) / sizeof(arr[0]);
  float largest = arr[0];
  float smallest = arr[0];
  for (int i = 0; i < count; i++) {
    if (largest < arr[i]) {
      largest = arr[i];
    }
    if (smallest > arr[i]) {
      smallest = arr[i];
    }
  }

  printf("The largest number is: %f\n", largest);
  printf("The smallest number is: %f\n", smallest);

  return 0;
}
