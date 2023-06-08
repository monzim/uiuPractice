#include <stdio.h>
#include <string.h>

#define MAX_BOWLERS 100

typedef struct {
  int wickets;
  int matches_played;
  int runs_conceded;
  char name[50];
  char country[50];
  float average;
} Bowler;

void calculate_average(Bowler *bowler) {
  if (bowler->wickets > 0) {
    bowler->average = (float)bowler->runs_conceded / bowler->wickets;
  } else {
    bowler->average = 0;
  }
}

int main() {
  Bowler bowlers[MAX_BOWLERS];
  int num_bowlers;

  printf("Enter the number of bowlers: ");
  scanf("%d", &num_bowlers);

  // Take input for each bowler
  for (int i = 0; i < num_bowlers; i++) {
    printf("\nBowler %d:\n", i + 1);
    printf("Name: ");
    scanf("%s", bowlers[i].name);
    printf("Country: ");
    scanf("%s", bowlers[i].country);
    printf("Total wickets taken: ");
    scanf("%d", &bowlers[i].wickets);
    printf("Total matches played: ");
    scanf("%d", &bowlers[i].matches_played);
    printf("Total runs conceded: ");
    scanf("%d", &bowlers[i].runs_conceded);

    // Calculate average
    calculate_average(&bowlers[i]);
  }

  // Find bowler with highest average
  Bowler highest_average_bowler = bowlers[0];
  for (int i = 1; i < num_bowlers; i++) {
    if (bowlers[i].average > highest_average_bowler.average) {
      highest_average_bowler = bowlers[i];
    }
  }

  // Print information of bowler with highest average
  printf("\nBowler with highest average:\n");
  printf("Name: %s\n", highest_average_bowler.name);
  printf("Country: %s\n", highest_average_bowler.country);
  printf("Total wickets taken: %d\n", highest_average_bowler.wickets);
  printf("Total matches played: %d\n", highest_average_bowler.matches_played);
  printf("Total runs conceded: %d\n", highest_average_bowler.runs_conceded);
  printf("Average: %.2f\n", highest_average_bowler.average);

  return 0;
}
