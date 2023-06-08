#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 500

int* read_input(int input[]) {
  char c;
  int i = 0;
  do {
    scanf("%d", &input[i]);
    scanf("%c", &c);
    i++;
  } while (c != '\n' && i < MAX_INPUT_SIZE);

  return input;
}

float calculateMin(int temp[], int num_of_elems) {
  float sum = 0, mean;

  for (int i = 0; i < num_of_elems; i++) {
    sum += temp[i];
  }

  mean = sum / num_of_elems;

  return mean;
}

float calc_dev(int temp[], int num_of_elems, float mean) {
  float sum_of_diff = 0, diff;

  for (int i = 0; i < num_of_elems; i++) {
    diff = mean - temp[i];
    diff = pow(diff, 2);
    sum_of_diff += diff;
  }

  float avg_of_diff = sum_of_diff / num_of_elems;
  float std_deviation = sqrt(avg_of_diff);

  return std_deviation;
}

int main(int argc, char* argv[]) {
  int input[MAX_INPUT_SIZE];
  int* input_address = read_input(input);

  int num_of_elems = 0;
  while (*(input_address + num_of_elems) != '\n') {
    num_of_elems++;
  }

  int array[num_of_elems];
  for (int i = 0; i < num_of_elems; i++) {
    array[i] = *(input_address + i);
  }

  float mean = calculateMin(array, num_of_elems);
  float std_deviation = calc_dev(array, num_of_elems, mean);

  printf("%.2f", std_deviation);

  return EXIT_SUCCESS;
}
