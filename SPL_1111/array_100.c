#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int array[100];
  // take inout from user
  for (int i = 0; i < 100; i++) {
    scanf("%d", &array[i]);
  }
  //
  //  int event_count = 0;
  //  int odd_count = 0;
  //
  //  int event_array[100];
  //  int odd_array[100];
  //
  //  for (int i = 0; i < 100; i++) {
  //    if (array[i] % 2 == 0) {
  //      event_array[event_count] = array[i];
  //      event_count++;
  //    } else {
  //      odd_array[odd_count] = array[i];
  //      odd_count++;
  //    }
  //  }
  //
  //  printf("\nEven numbers count: %d and their values are: ", event_count);
  //  for (int i = 0; i < event_count; i++) {
  //    printf("%d ", event_array[i]);
  //  }
  //
  //  printf("\nOdd numbers count: %d and their values are: ", odd_count);
  //  for (int i = 0; i < odd_count; i++) {
  //    printf("%d ", odd_array[i]);
  //  }
  //
  //  int unique_count = 0;
  //  int unique_array[100];
  //
  //  for (int i = 0; i < 100; i++) {
  //    int flag = 0;
  //    for (int j = 0; j < unique_count; j++) {
  //      if (array[i] == unique_array[j]) {
  //        flag = 1;
  //        break;
  //      }
  //    }
  //    if (flag == 0) {
  //      unique_array[unique_count] = array[i];
  //      unique_count++;
  //    }
  //  }
  //  // Find unique numbers using bit event_array
  int bit_array[100] = {1};

  int unique_count = 0;
  int unique_array[100];

  for (int i = 0; i < 100; i++) {
    if (bit_array[i] == 1) {
      unique_array[unique_count] = i;
      unique_count++;
    }
  }

  printf("\nUnique numbers count: %d and their values are: ", unique_count);

  return EXIT_SUCCESS;
}
