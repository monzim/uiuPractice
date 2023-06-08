/*
Write a program (WAP) that will find the grade of N students. For each student, it will
take the marks of his/her the attendance (on 5 marks), assignment (on 10 marks), class
test (on 15 marks), midterm (on 50 marks), term final (on 100 marks). Then based on the
tables shown below, the program will output his grade.
        Attendance (A) 5%
        Assignments (HW) 10%
        Class Tests (CT) 15%
        Midterm (MT) 30%
        Final (TF) 40%

Marks Letter Grade Marks Letter Grade Marks Letter Grade
90-100 A 70-73 C+ Less than 55 F
86-89 A- 66-69 C
82-85 B+ 62-65 C78-81 B 58-61 D+
74-77 B- 55-57 D

Sample input (A,HW,CT,MT,TF) Sample output
2                                       Student 1 : A
5 10 15 44.5 92.5                        Student 2 : F
0 7.5 5 20 55.5

*/

#include <stdio.h>

int main() {
  int n;
  double attendance, assignments, class_tests, midterm, final;
  int total_marks;
  char grade;

  printf("Enter the number of students: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    printf("Enter the marks for student %d (A,HW,CT,MT,TF): ", i);
    scanf("%lf%lf%lf%lf%lf", &attendance, &assignments, &class_tests, &midterm, &final);

    total_marks = attendance * 0.05 + assignments * 0.1 + class_tests * 0.15 + midterm * 0.3 + final * 0.4;

    if (total_marks >= 90) {
      grade = 'A';
    } else if (total_marks >= 86) {
      grade = 'A';
    } else if (total_marks >= 82) {
      grade = 'B';
    } else if (total_marks >= 78) {
      grade = 'B';
    } else if (total_marks >= 74) {
      grade = 'B';
    } else if (total_marks >= 70) {
      grade = 'C';
    } else if (total_marks >= 66) {
      grade = 'C';
    } else if (total_marks >= 62) {
      grade = 'C';
    } else if (total_marks >= 58) {
      grade = 'D';
    } else if (total_marks >= 55) {
      grade = 'D';
    } else {
      grade = 'F';
    }

    printf("Student %d: %c\n", i, grade);
  }

  return 0;
}
