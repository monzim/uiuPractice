#include <stdio.h>

void checkEvenOrOdd();
void evaluateEquation();
void incremnetSalary();

void main() {
  // check if the number ins even or odd
  int value;
  printf("Enter a number: ");
  scanf("%i", &value);

  if (value == 1) {
    checkEvenOrOdd();
  } else if (value == 2) {
    evaluateEquation();
  } else if (value == 3) {
    incremnetSalary();
  }

  else {
    printf("Invalid input. Goodbye!");
    return;
  }
}

void incremnetSalary() {
  float salary;
  printf("Enter your salary: ");
  scanf("%f", &salary);

  float increment = salary * 0.1;
  float new_salary = salary + increment;

  printf("Your new salary is: %f", new_salary);
}

void evaluateEquation() {
  float num1, num2;

  printf("Enter the first number: ");
  scanf("%f", &num1);

  printf("Enter the second number: ");
  scanf("%f", &num2);

  float calc = num1 + 0.175 * num2 - 10;
  printf("The result is: %f", calc);
}

void checkEvenOrOdd() {
  int num;
  printf("Enter a number: ");
  scanf("%i", &num);

  if (num % 2 == 0) {
    printf("The number is even");
  } else {
    printf("The number is odd");
  }
}