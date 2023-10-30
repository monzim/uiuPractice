
#include <stdio.h>

int menu();
void push(int *, int *, int);
void pop(int *, int *);
void display(int *, int *);
void pushMutiple(int *stack, int *top, int size);
void justPush(int *stack, int *top, int size, int data);

int main(int argc, char const *argv[]) {
  int size;
  int stack[100];

  for (;;) {
    switch (menu()) {
      case 1:
        push(stack, &size, 100);
        break;
      case 2:
        pop(stack, &size);
        break;
      case 3:
        display(stack, &size);
        break;
      case 4:
        return 0;
      case 5:
        pushMutiple(stack, &size, 100);
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}

int menu() {
  int choice;

  printf("1. Push\n");
  printf("2. Pop\n");
  printf("3. Display\n");
  printf("4. Exit\n");
  printf("5. Push multiple\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);
  return choice;
}

void pop(int *stack, int *top) {
  if (*top == -1) {
    printf("Stack is empty\n");
    return;
  }
  printf("Popped element: %d\n", stack[(*top)--]);
}

void display(int *stack, int *top) {
  if (*top == -1) {
    printf("Stack is empty\n");
    return;
  }
  printf("Stack: ");
  for (int i = 0; i <= *top; i++) {
    printf("%d ", stack[i]);
  }
  printf("\n");
}

void push(int *stack, int *top, int size) {
  if (*top == size - 1) {
    printf("Stack is full\n");
    return;
  }
  int data;
  printf("Enter data: ");
  scanf("%d", &data);
  stack[++(*top)] = data;
}

void justPush(int *stack, int *top, int size, int data) {
  if (*top == size - 1) {
    printf("Stack is full\n");
    return;
  }
  stack[++(*top)] = data;
}

void pushMutiple(int *stack, int *top, int size) {
  if (*top == size - 1) {
    printf("Stack is full\n");
    return;
  }

  int n;
  printf("Enter number of elements: ");
  scanf("%d", &n);

  if (*top + n >= size) {
    printf("Stack is full\n");
    return;
  }

  printf("Enter data: ");
  for (int i = 0; i < n; i++) {
    // scanf("%d", &stack[++(*top)]);
    int data;
    scanf("%d", &data);
    justPush(stack, top, size, data);
  }
}