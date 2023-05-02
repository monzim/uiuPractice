#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Hello {
  int id;
  int age;
};

int main(int argc, char *argv[]) {
  struct Hello h;

  printf("Enter age: ");
  scanf("%d", &h.age);

  printf("Enter id: ");
  scanf("%d", &h.id);

  printf("h.age = %d\n", h.age);
  printf("h.height = %d", h.id);

  return EXIT_SUCCESS;
}
