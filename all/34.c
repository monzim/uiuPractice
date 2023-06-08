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

int main(int argc, char *argv[]) {
  int num;
  printf("Enter a number : ");
  scanf("%d", &num);

  int num2;
  printf("Enter a number : ");
  scanf("%d", &num2);

  int num3;
  printf("Enter a number : ");
  scanf("%d", &num3);

  int arr[3] = {num2, num3, num};

  int size = sizeof(arr, arr[0]);

  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");

  for (int i = 0; i < size; i++) {
    arr[i] += 100 % 2;
    for (int i = 0; i < size; i++) {
      printf("%d, ", arr[i]);
    }
    printf("\n");
  }

  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");

    return EXIT_SUCCESS;
}
