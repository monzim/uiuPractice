#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main() {
  int array[10000000];

  qsort(array, 10000000, sizeof(int), compare);

  int largest = array[10000000 - 1];

  int secondLargest = array[10000000 - 2];

  int lowest = array[0];

  printf("Largest number: %d\n", largest);
  printf("Second largest number: %d\n", secondLargest);
  printf("Lowest number: %d\n", lowest);

  return 0;
}
