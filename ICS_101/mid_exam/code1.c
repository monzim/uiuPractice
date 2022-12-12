/*
PROBLEM-1: Write a program that converts a temperature from Fahrenheit to Celsius.

Example:
Enter the temperature in Fahrenheit: 32
The temperature in Celsius is 0.00

Enter the temperature in Fahrenheit: 212
The temperature in Celsius is 100.00

*/

#include <stdio.h>

int main(int argc, char *argv[]) {
  float fahrenheit, celsius;

  printf("Enter the temperature in Fahrenheit: ");
  scanf("%f", &fahrenheit);

  celsius = (fahrenheit - 32) * 5 / 9;

  printf("The temperature in Celsius is %.2f \n", celsius);

  return 0;
}
