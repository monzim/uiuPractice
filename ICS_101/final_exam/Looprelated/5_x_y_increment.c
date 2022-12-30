/*
Write a program (WAP) that will take two numbers X and Y as inputs. Then it will print
the square of X and increment (if X<Y) or decrement (if X>Y) X by 1, until X reaches Y. If
and when X is equal to Y, the program prints “Reached!”

10 5        100, 81, 64, 49, 36, Reached!
5 10        25, 36, 49, 64, 81, Reached!
10 10       Reached!

*/

#include <stdio.h>

int main() {
  int x, y;

  printf("Enter two numbers X and Y: ");
  scanf("%d%d", &x, &y);

  if (x < y) {
    // increment X by 1 until it reaches Y
    while (x <= y) {
      printf("%d^2 = %d\n", x, x * x);  // print the square of X
      x++;
    }
  } else if (x > y) {
    // decrement X by 1 until it reaches Y
    while (x >= y) {
      printf("%d^2 = %d\n", x, x * x);  // print the square of X
      x--;
    }
  }

  printf("Reached!\n");

  return 0;
}
