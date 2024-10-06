#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
  int data[MAX_SIZE];
  int top;
} Stack;

void initialize(Stack *stack) { stack->top = -1; }

bool push(Stack *stack, int item) {
  if (stack->top >= MAX_SIZE - 1) {
    return false;
  }
  stack->data[++stack->top] = item;
  return true;
}

int pop(Stack *stack) {
  if (stack->top < 0) {
    return -1;
  }
  return stack->data[stack->top--];
}

void display(Stack *stack) {
  for (int i = stack->top; i >= 0; i--) {
    printf("%d ", stack->data[i]);
  }
  printf("\n");
}

bool insertAtMiddle(Stack *stack, int item, int position) {
  if (position < 0 || position > stack->top + 1 || stack->top >= MAX_SIZE - 1) {
    return false;
  }

  Stack temp;
  initialize(&temp);

  for (int i = 0; i < stack->top - position + 1; i++) {
    push(&temp, pop(stack));
  }

  push(stack, item);

  while (temp.top >= 0) {
    push(stack, pop(&temp));
  }

  return true;
}

int main() {
  Stack stack;
  initialize(&stack);

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);
  push(&stack, 40);
  push(&stack, 50);

  printf("Original Stack: ");
  display(&stack);

  insertAtMiddle(&stack, 25, 2);

  printf("Stack after inserting 25 at position 2: ");
  display(&stack);

  return 0;
}
