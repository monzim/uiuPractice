#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    // Find the minimum element in the unsorted portion of the array
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    // Swap the minimum element with the first unsorted element
    int temp = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = temp;
  }
}

int main() {
  int n = 10000;
  int arr[n];
  srand(time(NULL));  // Initialize random seed
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 10000 + 1;  // Generate random integers between 1 and 10000
  }

  clock_t start_time = clock();
  selection_sort(arr, n);
  clock_t end_time = clock();
  double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

  printf("Time taken: %f seconds\n", time_taken);
  return 0;
}
