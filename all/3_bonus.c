#include <ctype.h>
#include <stdio.h>

void printGetBonus() { printf("Will Receive the Bonus\n"); }
void printNotBonus() { printf("Will Not Receive the Bonus\n"); }

int main(int argc, char *argv[]) {
  float salary, gIncome;
  int familyMembers, workExperience;
  char category;

  category = toupper(category);

  printf("Enter the category: ");
  scanf("%c", &category);

  while (category != 'X' && category != 'Y' && category != 'Z') {
    printf("Invalid Category. Please enter a valid category\n");
    printf("Enter the category: ");
    // sanity Check
    getchar();
    scanf("%c", &category);
    category = toupper(category);
  }

  printf("work experience: ");
  scanf("%d", &workExperience);

  printf("family members: ");
  scanf("%d", &familyMembers);

  printf("income: ");
  scanf("%f", &gIncome);

  if ((workExperience >= 12 && familyMembers > 5) || (gIncome < 1000.50)) {
    printGetBonus();

  } else {
    if (((category == 'Y' || category == 'Z') || category == 'y' ||
         category == 'z') ||
        (familyMembers > 8) && (gIncome < 1100.78)) {
      printGetBonus();

    } else {
      if ((category == 'X' || category == 'x') && familyMembers > 5) {
        printGetBonus();

      } else {
        printNotBonus();
      }
    }
  }

  return 0;
}
