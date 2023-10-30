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
    // Return a sentinel value to indicate an empty stack.
    return -1;
  }
  return stack->data[stack->top--];
}

int find(Stack *stack, int item) {
  for (int i = stack->top; i >= 0; i--) {
    if (stack->data[i] == item) {
      return i;
    }
  }
  return -1;
}

void removeElement(Stack *stack, int item) {
  int index = find(stack, item);
  if (index != -1) {
    for (int i = index; i < stack->top; i++) {
      stack->data[i] = stack->data[i + 1];
    }
    stack->top--;
  }
}

int last(Stack *stack) {
  if (stack->top < 0) {
    return -1;
  }
  return stack->data[stack->top];
}

int first(Stack *stack) {
  if (stack->top < 0) {
    return -1;
  }
  return stack->data[0];
}

void display(Stack *stack) {
  for (int i = stack->top; i >= 0; i--) {
    printf("%d ", stack->data[i]);
  }
  printf("\n");
}

void useMe() {
  Stack stack;
  initialize(&stack);
  push(&stack, 1);
  push(&stack, 2);
  push(&stack, 3);
  display(&stack);

  int item = pop(&stack);
  if (item != -1) {
    printf("Popped item: %d\n", item);
  }

  removeElement(&stack, 2);
  printf("Stack after removing 2: ");
  display(&stack);

  printf("Index of 1: %d\n", find(&stack, 1));
  printf("Last item: %d\n", last(&stack));
  printf("First item: %d\n", first(&stack));
}

int main() {
  useMe();
  return 0;
}
