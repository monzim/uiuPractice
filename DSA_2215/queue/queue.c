#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
  int data[MAX_SIZE];
  int front, rear;
} Queue;

void initialize(Queue *queue) {
  queue->front = -1;
  queue->rear = -1;
}

bool isFull(Queue *queue) { return (queue->rear == MAX_SIZE - 1); }

bool isEmpty(Queue *queue) { return (queue->front == -1); }

bool add(Queue *queue, int item) {
  if (isFull(queue)) {
    return false;
  }
  if (isEmpty(queue)) {
    queue->front = 0;
  }
  queue->rear++;
  queue->data[queue->rear] = item;
  return true;
}

int removeEl(Queue *queue) {
  if (isEmpty(queue)) {
    return -1;
  }
  int item = queue->data[queue->front];
  if (queue->front == queue->rear) {
    queue->front = -1;
    queue->rear = -1;
  } else {
    queue->front++;
  }
  return item;
}

void show(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements: ");
  for (int i = queue->front; i <= queue->rear; i++) {
    printf("%d ", queue->data[i]);
  }
  printf("\n");
}

int middle(Queue *queue) {
  if (isEmpty(queue)) {
    return -1;
  }
  int fast = queue->front;
  int slow = queue->front;
  while (fast != -1 && fast != queue->rear) {
    fast = (fast + 2 <= queue->rear) ? fast + 2 : fast;
    slow = slow + 1;
  }
  return queue->data[slow];
}

bool search(Queue *queue, int item) {
  for (int i = queue->front; i <= queue->rear; i++) {
    if (queue->data[i] == item) {
      return true;
    }
  }
  return false;
}

int main() {
  Queue queue;
  initialize(&queue);
  int choice, item;

  while (1) {
    printf("\nQueue Operations:\n");
    printf("1. Add\n");
    printf("2. Remove\n");
    printf("3. Show\n");
    printf("4. Middle\n");
    printf("5. Search\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the item to add: ");
        scanf("%d", &item);
        if (add(&queue, item)) {
          printf("Item %d added to the queue.\n", item);
        } else {
          printf("Queue is full. Item not added.\n");
        }
        break;

      case 2:
        item = removeEl(&queue);
        if (item != -1) {
          printf("Removed item: %d\n", item);
        } else {
          printf("Queue is empty. Nothing to remove.\n");
        }
        break;

      case 3:
        show(&queue);
        break;

      case 4:
        item = middle(&queue);
        if (item != -1) {
          printf("Middle element: %d\n", item);
        } else {
          printf("Queue is empty. No middle element.\n");
        }
        break;

      case 5:
        printf("Enter the item to search: ");
        scanf("%d", &item);
        if (search(&queue, item)) {
          printf("Item found in the queue.\n");
        } else {
          printf("Item not found in the queue.\n");
        }
        break;

      case 6:
        return 0;

      default:
        printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
