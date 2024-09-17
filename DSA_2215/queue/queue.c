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

bool isFull(Queue *queue) { return ((queue->rear + 1) % MAX_SIZE == queue->front); }

bool isEmpty(Queue *queue) { return (queue->front == -1); }

int currentSize(Queue *queue) {
  if (isEmpty(queue)) {
    return 0;
  }

  return (queue->rear >= queue->front) ? (queue->rear - queue->front + 1) : (MAX_SIZE - queue->front + queue->rear + 1);
}

bool add(Queue *queue, int item) {
  if (isFull(queue)) {
    return false;
  }
  if (isEmpty(queue)) {
    queue->front = 0;
  }
  queue->rear = (queue->rear + 1) % MAX_SIZE;
  queue->data[queue->rear] = item;
  return true;
}

int removeEl(Queue *queue) {
  if (isEmpty(queue)) {
    return -1;
  }
  int item = queue->data[queue->front];
  if (queue->front == queue->rear) {
    // If only one element was left, reset the queue
    queue->front = -1;
    queue->rear = -1;
  } else {
    queue->front = (queue->front + 1) % MAX_SIZE;
  }
  return item;
}

void show(Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue elements: ");
  int i = queue->front;
  while (i != queue->rear) {
    printf("%d ", queue->data[i]);
    i = (i + 1) % MAX_SIZE;
  }
  printf("%d\n", queue->data[queue->rear]);  // Print the last element
}

int middle(Queue *queue) {
  if (isEmpty(queue)) {
    return -1;
  }
  int slow = queue->front;
  int fast = queue->front;

  while (fast != queue->rear && (fast + 1) % MAX_SIZE != queue->rear) {
    fast = (fast + 2) % MAX_SIZE;
    slow = (slow + 1) % MAX_SIZE;
  }
  return queue->data[slow];
}

bool search(Queue *queue, int item) {
  if (isEmpty(queue)) {
    return false;
  }
  int i = queue->front;
  while (i != queue->rear) {
    if (queue->data[i] == item) {
      return true;
    }
    i = (i + 1) % MAX_SIZE;
  }
  return (queue->data[queue->rear] == item);  // Check the last element
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
