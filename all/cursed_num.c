#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int startCheck(int a) {
  int last = a % 10;
  int first = a;
  while (first >= 10) {
    first /= 10;
  }
  return (first == 1 || first == 7) && (last != 2 && last != 9) ? 1 : -1;
}

int posCheck(int a) {
  int eev = 0;
  int od = 0;
  while (a > 0) {
    int digit = a % 10;
    if (eev % 2 == 0 && digit % 2 != 0) {
      return -1;
    }
    if (od % 2 != 0 && digit % 2 == 0) {
      return -1;
    }
    eev++;
    od++;
    a /= 10;
  }
  return 1;
}

int facto(int a) {
  int org = a;
  int sum = 0;
  while (a > 0) {
    int digit = a % 10;
    int factorial = 1;
    for (int i = 1; i <= digit; i++) {
      factorial *= i;
    }
    sum += factorial;
    a /= 10;
  }
  return sum == org ? 1 : -1;
}

int checkerFunc4(int a) {
  int sum_sqt = 0;
  while (a > 0) {
    int digit = a % 10;
    sum_sqt += pow(digit, 2);
    a /= 10;
  }
  return sum_sqt % 7 == 0 ? 1 : -1;
}

int isStrong(int a) {
  int org = a;
  int sum = 0;
  while (a > 0) {
    int digit = a % 10;
    int factorial = 1;
    for (int i = 1; i <= digit; i++) {
      factorial *= i;
    }
    sum += factorial;
    a /= 10;
  }
  return sum == org ? 1 : -1;
}

int defectiveCheck(int a) {
  int sum_of_div = 0;
  for (int i = 1; i < a; i++) {
    if (a % i == 0) {
      sum_of_div += i;
    }
  }
  return sum_of_div < 2 * a ? 1 : -1;
}

int sectumCheck(int a) {
  return startCheck(a) == 1 && posCheck(a) == 1 && facto(a) == 1 && checkerFunc4(a) == 1 && isStrong(a) == 1 &&
                 defectiveCheck(a) == -1
             ? 1
             : -1;
}

int main() {
  int low, high;
  printf("lower: ");
  scanf("%d", &low);

  printf("upper ");
  scanf("%d", &high);

  printf("Cursed Numbers in the range [%d, %d]:\n", low, high);
  for (int i = low; i <= high; i++) {
    if (sectumCheck(i) == 1) {
      printf("%d\n", i);
    }
  }
  return EXIT_SUCCESS;
}
