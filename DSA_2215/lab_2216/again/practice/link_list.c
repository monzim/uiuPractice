#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
typedef struct Node {
  int data;
  struct Node* next;
} Node;

// Node structure for doubly linked list
typedef struct DNode {
  int data;
  struct DNode* next;
  struct DNode* prev;
} DNode;

// Singly Linked List Operations

// Insert at Beginning
void insertAtBeginning(Node** head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = *head;
  *head = newNode;
}

// Insert at End
void insertAtEnd(Node** head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
    return;
  }

  Node* temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}

// Insert at Position
void insertAtPosition(Node** head, int data, int position) {
  if (position < 0) {
    printf("Invalid position\n");
    return;
  }

  if (position == 0) {
    insertAtBeginning(head, data);
    return;
  }

  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;

  Node* temp = *head;
  for (int i = 0; i < position - 1; i++) {
    if (temp == NULL) {
      printf("Position exceeds the length of the list\n");
      free(newNode);
      return;
    }
    temp = temp->next;
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

// Delete from Beginning
void deleteFromBeginning(Node** head) {
  if (*head == NULL) return;

  Node* temp = *head;
  *head = (*head)->next;
  free(temp);
}

// Delete from End
void deleteFromEnd(Node** head) {
  if (*head == NULL) return;

  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }

  Node* temp = *head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }

  free(temp->next);
  temp->next = NULL;
}

// Delete at Position
void deleteAtPosition(Node** head, int position) {
  if (position < 0 || *head == NULL) return;

  if (position == 0) {
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
  }

  Node* temp = *head;
  for (int i = 0; i < position - 1; i++) {
    if (temp == NULL || temp->next == NULL) return;
    temp = temp->next;
  }

  Node* toDelete = temp->next;
  temp->next = temp->next->next;
  free(toDelete);
}

// Search Element
int searchElement(Node* head, int data) {
  Node* temp = head;
  while (temp != NULL) {
    if (temp->data == data) {
      return 1;  // Found
    }
    temp = temp->next;
  }
  return 0;  // Not found
}

// Find Middle Element
Node* findMiddle(Node* head) {
  Node* slow = head;
  Node* fast = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

// Doubly Linked List Operations

// Insert at Beginning
void insertAtBeginningD(DNode** head, int data) {
  DNode* newNode = (DNode*)malloc(sizeof(DNode));
  newNode->data = data;
  newNode->next = *head;
  newNode->prev = NULL;

  if (*head != NULL) {
    (*head)->prev = newNode;
  }

  *head = newNode;
}

// Insert at End
void insertAtEndD(DNode** head, int data) {
  DNode* newNode = (DNode*)malloc(sizeof(DNode));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    newNode->prev = NULL;
    *head = newNode;
    return;
  }

  DNode* temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
}

// Insert at Position
void insertAtPositionD(DNode** head, int data, int position) {
  if (position < 0) {
    printf("Invalid position\n");
    return;
  }

  if (position == 0) {
    insertAtBeginningD(head, data);
    return;
  }

  DNode* newNode = (DNode*)malloc(sizeof(DNode));
  newNode->data = data;

  DNode* temp = *head;
  for (int i = 0; i < position - 1; i++) {
    if (temp == NULL) {
      printf("Position exceeds the length of the list\n");
      free(newNode);
      return;
    }
    temp = temp->next;
  }

  newNode->next = temp->next;
  if (temp->next != NULL) {
    temp->next->prev = newNode;
  }
  temp->next = newNode;
  newNode->prev = temp;
}

// Delete from Beginning
void deleteFromBeginningD(DNode** head) {
  if (*head == NULL) return;

  DNode* temp = *head;
  *head = (*head)->next;

  if (*head != NULL) {
    (*head)->prev = NULL;
  }

  free(temp);
}

// Delete from End
void deleteFromEndD(DNode** head) {
  if (*head == NULL) return;

  DNode* temp = *head;
  if (temp->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }

  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->prev->next = NULL;
  free(temp);
}

// Delete at Position
void deleteAtPositionD(DNode** head, int position) {
  if (position < 0 || *head == NULL) return;

  DNode* temp = *head;

  if (position == 0) {
    *head = temp->next;
    if (temp->next != NULL) {
      temp->next->prev = NULL;
    }
    free(temp);
    return;
  }

  for (int i = 0; i < position; i++) {
    if (temp == NULL) return;
    temp = temp->next;
  }

  if (temp == NULL) return;

  if (temp->next != NULL) {
    temp->next->prev = temp->prev;
  }

  if (temp->prev != NULL) {
    temp->prev->next = temp->next;
  }

  free(temp);
}

// Search Element
int searchElementD(DNode* head, int data) {
  DNode* temp = head;
  while (temp != NULL) {
    if (temp->data == data) {
      return 1;  // Found
    }
    temp = temp->next;
  }
  return 0;  // Not found
}

// Find Middle Element
DNode* findMiddleD(DNode* head) {
  DNode* slow = head;
  DNode* fast = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

// Main Function
int main() {
  // Singly linked list operations
  Node* singlyList = NULL;
  insertAtBeginning(&singlyList, 1);
  insertAtEnd(&singlyList, 3);
  insertAtPosition(&singlyList, 2, 1);
  insertAtPosition(&singlyList, 4, 3);

  printf("Singly Linked List:\n");
  Node* current = singlyList;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");

  deleteFromBeginning(&singlyList);
  deleteFromEnd(&singlyList);
  deleteAtPosition(&singlyList, 1);
  printf("Singly List After Deletion: ");
  current = singlyList;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");

  int searchElementVal = 2;
  printf("Search for element %d in Singly List: %d\n", searchElementVal, searchElement(singlyList, searchElementVal));

  insertAtEnd(&singlyList, 5);
  insertAtEnd(&singlyList, 6);
  Node* middleSingly = findMiddle(singlyList);
  printf("Middle element in Singly List: %d\n", middleSingly->data);

  // Doubly linked list operations
  DNode* doublyList = NULL;
  insertAtBeginningD(&doublyList, 1);
  insertAtEndD(&doublyList, 3);
  insertAtPositionD(&doublyList, 2, 1);
  insertAtPositionD(&doublyList, 4, 3);

  printf("Doubly Linked List:\n");
  DNode* currentD = doublyList;
  while (currentD != NULL) {
    printf("%d -> ", currentD->data);
    currentD = currentD->next;
  }
  printf("NULL\n");

  deleteFromBeginningD(&doublyList);
  deleteFromEndD(&doublyList);
  deleteAtPositionD(&doublyList, 1);
  printf("Doubly List After Deletion: ");
  currentD = doublyList;
  while (currentD != NULL) {
    printf("%d -> ", currentD->data);
    currentD = currentD->next;
  }
  printf("NULL\n");

  printf("Search for element %d in Doubly List: %d\n", searchElementVal, searchElementD(doublyList, searchElementVal));

  insertAtEndD(&doublyList, 5);
  insertAtEndD(&doublyList, 6);
  DNode* middleDoubly = findMiddleD(doublyList);
  printf("Middle element in Doubly List: %d\n", middleDoubly->data);

  return 0;
}
