#include <stdio.h>

int main() {
  int num, count = 0;
  float sum = 0.0, avg;

  while (1) {
    printf("Enter a positive number (0 to stop): ");
    scanf("%d", &num);

    if (num == 0) {
      break;
    }

    if (num > 0) {
      sum += num;
      count++;
      avg = sum / count;
      printf("Online average: %.2f\n", avg);
    }
  }

  printf("Final average: %.2f\n", avg);

  return 0;
}
