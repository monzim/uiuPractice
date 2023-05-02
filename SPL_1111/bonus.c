#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[]) {

  float salarey[6][2] = {{1000, 0.1}, {2000, 0.2}, {3000, 0.3},
                         {4000, 0.4}, {5000, 0.5}, {6000, 0.6}};

  for (int i = 0; i < 6; i++) {
    float bonus = salarey[i][0] * salarey[i][1];
    float eidSalarey = salarey[i][0] + bonus;

    printf("Employee %d salarey is %f and bonus is %f Total: %f", i,
           salarey[i][0], bonus, eidSalarey);
    printf("\n");
  };

  return EXIT_SUCCESS;
}
