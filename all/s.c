#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int array[], int size) {
  int minIndex, temp;
  for (int i = 0; i < size - 1; i++) {
    minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (array[j] < array[minIndex]) {
        minIndex = j;
      }
    }

    temp = array[i];
    array[i] = array[minIndex];
    array[minIndex] = temp;
  }
}

int main() {
  int array[5] = {44, 33, 41, 53, 66};
  clock_t startTime = clock();

  srand(time(NULL));
  selectionSort(array, 5);
  clock_t endTime = clock();

  double timeNeed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

  printf("Time take: %f sec", timeNeed);
  for (int i = 0; i < 5; i++) {
    printf("%d, ", array[i]);
  }

  return 0;
}