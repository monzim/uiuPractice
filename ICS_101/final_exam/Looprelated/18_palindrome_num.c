/*
will determine whether an integer is palindrome number or not.
    Sample input Sample output
        9       Yes
        91      No
        222     Yes
        12321   Yes
        110     No
*/

#include <stdio.h>
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

int main() {
  printf("%d\n", is_palindrome(121));
  printf("%d\n", is_palindrome(123));
  printf("%d\n", is_palindrome(1221));
  return 0;
}
