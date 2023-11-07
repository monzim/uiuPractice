#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
  int data;
  struct Node *next, *prev;
};

typedef struct Node Node;

Node* createNode(int value);
Node* insertHead(Node* head, int value);
Node* insertTail(Node* head, int value);
Node* insertNth(Node* head, int position, int value);
Node* deleteHead(Node* head);
Node* deleteTail(Node* head);
Node* deleteNth(Node* head, int position);
Node* insertNValues(Node* head, int n);

int menu();
int listSize(Node* head);
void printList(Node* head);
void printReverseList(Node* head);

int main() {
  Node* head = NULL;
  int choice, value, position;

  choice = menu();

  while (choice != 0) {
    if (choice == 1) {
      printf("\nInsert value: ");
      scanf("%d", &value);
      head = insertHead(head, value);
    } else if (choice == 2) {
      printf("\nInsert value: ");
      scanf("%d", &value);
      head = insertTail(head, value);
    } else if (choice == 3) {
      printf("\nInsert position: ");
      scanf("%d", &position);
      if (position > listSize(head) + 1) {
        printf("\nInvalid position.\n");
      } else {
        printf("\nInsert value: ");
        scanf("%d", &value);
        head = insertNth(head, position, value);
      }
    } else if (choice == 4) {
      head = deleteHead(head);
    } else if (choice == 5) {
      head = deleteTail(head);
    } else if (choice == 6) {
      printf("\nDelete position: ");
      scanf("%d", &position);
      head = deleteNth(head, position);
    } else if (choice == 7) {
      printf("Enter how many values you want to insert: ");
      scanf("%d", &value);
      head = insertNValues(head, value);
    } else if (choice == 9) {
      printList(head);
    } else if (choice == 10) {
      printReverseList(head);
    }

    choice = menu();
  }
}

int menu() {
  int choice;
  printf("1. Insert at the head\n");
  printf("2. Insert at the tail\n");
  printf("3. Insert at nth position\n");
  printf("4. Delete from the head\n");
  printf("5. Delete from the tail\n");
  printf("6. Delete from nth position\n");
  printf("7. Insert N values\n");
  printf("8. List size\n");
  printf("9. Print list\n");
  printf("10. Print list in reverse\n");
  printf("0. Exit\n");
  printf("\nEnter your choice: ");
  scanf("%d", &choice);
  return choice;
}

Node* createNode(int value) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  if (!newNode) {
    printf("Memory allocation error.\n");
    exit(1);
  }
  newNode->data = value;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

Node* insertHead(Node* head, int value) {
  Node* newNode = createNode(value);
  if (head != NULL) {
    newNode->next = head;
    head->prev = newNode;
  }
  head = newNode;
  return head;
}

void printList(Node* head) {
  Node* current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n\n");
}

Node* insertTail(Node* head, int value) {
  if (head == NULL) {
    head = insertHead(head, value);
  } else {
    Node* newNode = createNode(value);
    Node* current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
  }
  return head;
}

int listSize(Node* head) {
  int size = 0;
  Node* current = head;
  while (current != NULL) {
    size++;
    current = current->next;
  }
  return size;
}

Node* insertNth(Node* head, int position, int value) {
  if (position == 1) {
    head = insertHead(head, value);
  } else if (position == listSize(head) + 1) {
    head = insertTail(head, value);
  } else {
    Node* newNode = createNode(value);
    Node* current = head;
    while (position - 2 > 0) {
      current = current->next;
      position--;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;
    newNode->next->prev = newNode;
  }
  return head;
}

Node* deleteHead(Node* head) {
  if (head == NULL) {
    printf("\nList is empty.\n");
  } else {
    Node* deletedNode = head;
    head = head->next;
    if (head != NULL) {
      head->prev = NULL;
    }
    free(deletedNode);
  }
  return head;
}

Node* deleteTail(Node* head) {
  if (head == NULL) {
    printf("\nList is empty.\n");
  } else if (head->next == NULL) {
    head = deleteHead(head);
  } else {
    Node* current = head;
    while (current->next->next != NULL) {
      current = current->next;
    }
    Node* deletedNode = current->next;
    current->next = NULL;
    free(deletedNode);
  }
  return head;
}

Node* deleteNth(Node* head, int position) {
  if (position == 1) {
    head = deleteHead(head);
  } else if (position == listSize(head)) {
    head = deleteTail(head);
  } else if (position < 1 || position > listSize(head)) {
    printf("\nInvalid position.\n");
  } else {
    Node* current = head;
    while (position - 2 > 0) {
      current = current->next;
      position--;
    }
    Node* deletedNode = current->next;
    current->next = deletedNode->next;
    deletedNode->next->prev = current;
    free(deletedNode);
  }
  return head;
}

Node* insertNValues(Node* head, int n) {
  Node* current;
  int i, value, position;

  srand(time(NULL));

  for (i = 1; i <= n; i++) {
    current = head;
    value = (rand() % 100) + 1;
    if (current == NULL) {
      head = insertHead(head, value);
    } else {
      position = 1;
      while (current != NULL && current->data <= value) {
        current = current->next;
        position++;
      }
      head = insertNth(head, position, value);
    }
  }

  return head;
}

void printReverseList(Node* head) {
  Node* current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->prev;
  }
  printf("\n\n");
}
