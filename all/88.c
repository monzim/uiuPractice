#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

int main() {
  int num;
  printf("Enter a number : ");
  scanf("%d", &num);

  int a = 36;

  int b = 67;

  int tmp = a - b;

  printf(" %d and %d is %d\n", a, b, tmp);

  a = 25;

  b = 84;

  int sum = a + b;

  int arr[100];

  printf("The sum of %d and %d is %d\n", a, b, sum);

  scanf("%d", &arr[0]);

  for (int i = 0; i < 100; i++) {
    printf("%d\n", arr[i]);
  }

  return 0;
}
