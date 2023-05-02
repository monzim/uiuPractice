#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(int n) {
  char str[10];
  sprintf(str, "%d", n);

  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      return 0;
    }
  }
  return 1;
}

int totalNum(int n) {
  if (n == 0)
    return 0;
  return 1 + totalNum(n / 10);
}

int checkNumPossion(int n, int pos) {
  if (pos == 0)
    return n % 10;
  return checkNumPossion(n / 10, pos - 1);
}

int sqt_ODD_POS(int n) {
  int total = totalNum(n);
  int sum = 0;

 if (total == 1)
    return 0;
 
 int digit = n % 10;
 int pos = checkNumPossion(n, digit);

 if(pos % 2 != 0){
      int val = digit * digit + sqt_ODD_POS(n / 10);
      sum += val;

 }

 return q



}

int squre_root_odd_digits(int n) {
  if (n == 0)
    return 0;
  int digit = n % 10;
  if (digit % 2 == 0) {
    return squre_root_odd_digits(n / 10);
  }
  return digit * digit + squre_root_odd_digits(n / 10);
}

int have_odd_digit_in_event_pos(int n) {
  if (n == 0)
    return 0;
  int digit = n % 10;
  if (digit % 2 == 1) {
    return 1;
  }
  return have_odd_digit_in_event_pos(n / 100);
}

int main(void) {
  int n;
  scanf("%d", &n);

  if (is_palindrome(n)) {
    int sum_Of_ODD = sqt_ODD_POS(n);
    int dont_have_odd = have_odd_digit_in_event_pos(n);
    if (sum_Of_ODD % 4 == 0 && dont_have_odd == 0) {
      printf("%d SQUID\n", n);
    } else {
      printf("%d SQUID\n", n);
    }

  } else {
    printf("%d is not palindrome\n", n);
  }

  return EXIT_SUCCESS;
}
