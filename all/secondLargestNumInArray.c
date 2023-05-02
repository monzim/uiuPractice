#include <stdio.h>

float getLargest(float arr[], int count);
int length(float arr[]);

void main() {
  //  How many number user want to compare
  //  Add those number in a array
  // TODO: Get the largest number from the array
  // TODO: Get the smallest number from the array
  // TODO: Create a new array and remove the largest number then Calculate again
  // the Largest number

  int count;
  printf("How many number you want to calculate? ");
  scanf("%i", &count);

  printf("Enter %i integers separate with SPACE: ", count);
  float arr[count];
  for (int i = 0; i < count; i++) {
    scanf("%f", &arr[i]);
  }

  //   Get the largest number
  // float largest;
  // for (size_t i = 0; i < count; i++) {
  //   float lar = arr[0];
  //   if (lar < arr[i]) {
  //     lar = arr[i];
  //     largest = lar;
  //   }
  // }

  float largest = getLargest(arr, count);

  // remove the largest number
  float new_arr[count - 1];
  for (size_t i = 0; i < count; i++) {
    if (arr[i] != largest) {
      new_arr[i] = arr[i];
    }
  }

  float second_largest = getLargest(new_arr, count - 1);
  // print the second largest number
  printf("The second largest number is: %f ", second_largest);
}

// get the largest number
float getLargest(float arr[], int count) {
  float largest;

  for (size_t i = 0; i < count; i++) {
    float lar = arr[0];
    if (lar < arr[i]) {
      lar = arr[i];
      largest = lar;
    }
  }
  return largest;
}

int length(float arr[]) {
  int count = 0;
  while (arr[count] != '\0') {
    count++;
  }
  return count;
}
