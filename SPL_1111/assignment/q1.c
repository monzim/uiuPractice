#include <stdio.h>
// #include <studio.h>
int main() {
  int a = 17 % 7 * 5;
  float b = (int)(17.0 / 5);
  float c = (int)17 / 5.0;
  int d = (a > b) && c;

  printf("a = %d", a);
  printf("b = %f", b);
  printf("c = %f", c);
  printf("d = %d", d);

  // print all the values
  return 0;
}

/*
Compute the values of the variables a, b, c, and d.
 int a = 17%7*5;
 float b = (int)(17.0/5);
 float c= (int)17/5.0;
 int d = (a>b) && c;

What is the output of the following program?a
a = 17%7*5;
b = (int)(17.0/5);
c= (int)17/5.0;
d = (a>b) && c;
*/