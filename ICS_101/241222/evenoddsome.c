#include <stdio.h>

int main(int argc, char *argv[]) {
  int n;
  printf("Enter the number of integers: ");
  scanf("%d", &n);

  float oddSum = 0, evenSum = 0;
  int oddCount = 0, evenCount = 0;
  float num;

  for (int i = 0; i < n; i++) {
    printf("Enter integer %d: ", i + 1);
    scanf("%f", &num);

    if ((int)num % 2 == 0) {
      evenSum += num;
      evenCount++;
    } else {
      oddSum += num;
      oddCount++;
    }
  }

  printf("OddSum: %f\n", oddSum);
  printf("EvenSum: %f\n", evenSum);
  printf("Average Even: %f\n", evenSum / evenCount);
  printf("Average Odd: %f\n", oddSum / oddCount);

  return 0;
}