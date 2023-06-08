#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define FILENAME "Sample.txt"
#define OUTPUTFILE "Output.txt"

void print_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
}

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

  FILE *fp2 = fopen(OUTPUTFILE, "w");
  if (fp2 == NULL) {
    printf("Error opening file %s\n", OUTPUTFILE);
    return EXIT_FAILURE;
  }

  for (int j = 0; j < i; j++) {
    if (arr[j] % 2 == 0) {
      fprintf(fp2, "%d\n", arr[j]);
    }
  }

  print_array(arr, i);

  return EXIT_SUCCESS;
}
