/*
PROBLEM-3: Float salary,integer family members and work experience in years
Type-1:work exp more than or equal to 12 years and family members 5 or more members
Type2:work experience more than or equal to 20 and family members 7 or more
Type 3 :work experience less than 5 years and family members 10 or more

Type 1: 15% of salary
Type 2: 25% of salary
Type 3: 12% of salary
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
  float salary;
  int family_members, work_experience;

  printf("Enter the salary: ");
  scanf("%f", &salary);

  printf("Enter the family members: ");
  scanf("%d", &family_members);

  printf("Enter the work experience: ");
  scanf("%d", &work_experience);

  if (work_experience >= 12 && work_experience < 20 && family_members >= 5) {
    salary = salary + salary * 0.15;
  } else if (work_experience >= 20 && family_members >= 7) {
    salary = salary * 1.25;
  } else if (work_experience < 5 && family_members >= 10) {
    salary = salary + salary * 0.12;
  } else {
    printf("No increment \n");
  }

  printf("The salary is: %.2f \n", salary);

  return 0;
}
