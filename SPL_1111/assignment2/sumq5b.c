#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define FILENAME "numbers.txt"

int main(int argc, char *argv[]) {
  int arr[MAX] = {0};

  FILE *fp = fopen(FILENAME, "r");
  if (fp == NULL) {
    printf("Error opening file %s\n", FILENAME);
    return EXIT_FAILURE;
  }

  int i = 0;
  while (fscanf(fp, "%d", &arr[i]) != EOF) {
    i++;
    arr[i] = 0;
  }

  if (sizeof(arr) == 0) {
    printf("No data in file");
    return EXIT_SUCCESS;
  }

  //  middle element of array
  int middle = i / 2;
  printf("Middle element of array is %d\n", arr[middle]);

  return EXIT_SUCCESS;
}
