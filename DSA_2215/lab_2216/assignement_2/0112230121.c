#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};
typedef struct Node node;

int menu();
node* create_node(int v);
node* insert_head(node* head, int v);
void print_list(node* head);
node* insert_tail(node* head, int v);
int list_size(node* head);
node* insert_nth(node* head, int pos, int v);
node* delete_head(node* head);
node* delete_tail(node* head);
node* delete_nth(node* head, int pos);

int main() {
  node* head = NULL;
  int choice, x, pos;

  choice = menu();

  while (choice != 0) {
    if (choice == 1) {
      printf("\ninsert value: ");
      scanf("%d", &x);
      head = insert_head(head, x);
    }

    else if (choice == 2) {
      printf("\ninsert value: ");
      scanf("%d", &x);
      head = insert_tail(head, x);
    }

    else if (choice == 3) {
      printf("\ninsert position: ");
      scanf("%d", &pos);
      if (pos > list_size(head) + 1) {
        printf("\ninvalid position.\n");
      } else {
        printf("\ninsert value: ");
        scanf("%d", &x);
        head = insert_nth(head, pos, x);
      }
    }

    else if (choice == 4) {
      head = delete_head(head);
    }

    else if (choice == 5) {
      head = delete_tail(head);
    }

    else if (choice == 6) {
      printf("\ndelete position: ");
      scanf("%d", &pos);
      if (pos > list_size(head) || pos <= 0) {
        printf("\ninvalid position.\n");
      } else {
        head = delete_nth(head, pos);
      }
    }

    else if (choice == 8) {
      printf("Size of the list: %d\n", list_size(head));
    }

    else if (choice == 9) {
      print_list(head);
    }

    choice = menu();
  }

  return 0;
}

int menu() {
  int x;
  printf("1. insert_head\n");
  printf("2. insert_tail\n");
  printf("3. insert_nth\n");
  printf("4. delete_head\n");
  printf("5. delete_tail\n");
  printf("6. delete_nth\n");
  printf("8. size\n");
  printf("9. print list\n");
  printf("0. exit\n");

  printf("\nenter choice: ");
  scanf("%d", &x);
  return x;
}

node* insert_head(node* head, int v) {
  node* new_node = create_node(v);

  if (head != NULL) {
    new_node->next = head;
  }
  head = new_node;

  return head;
}

node* create_node(int v) {
  node* temp = (node*)malloc(sizeof(node));
  temp->data = v;
  temp->next = NULL;
  return temp;
}

void print_list(node* head) {
  node* temp = head;

  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n\n");
}

node* insert_tail(node* head, int v) {
  if (head == NULL) {
    head = insert_head(head, v);
  } else {
    node *new_node, *temp = head;
    new_node = create_node(v);

    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_node;
  }

  return head;
}

int list_size(node* head) {
  int x = 0;
  node* temp = head;
  while (temp != NULL) {
    temp = temp->next;
    x++;
  }
  return x;
}

node* insert_nth(node* head, int pos, int v) {
  if (pos == 1) {
    head = insert_head(head, v);
  } else if (pos == list_size(head) + 1) {
    head = insert_tail(head, v);
  } else {
    node *new_node, *temp = head;
    new_node = create_node(v);

    while (pos - 2 > 0) {
      temp = temp->next;
      pos--;
    }
    new_node->next = temp->next;
    temp->next = new_node;
  }

  return head;
}

node* delete_head(node* head) {
  if (head == NULL) {
    printf("\nlist is empty.\n");
  } else {
    node* dlt = head;
    head = head->next;
    free(dlt);
  }
  return head;
}

node* delete_tail(node* head) {
  if (head == NULL) {
    printf("\nlist is empty.\n");
  } else if (head->next == NULL) {
    head = delete_head(head);
  } else {
    node* temp = head;

    while (temp->next->next != NULL) {
      temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
  }
  return head;
}

node* delete_nth(node* head, int pos) {
  if (pos == 1) {
    return delete_head(head);
  } else {
    node* temp = head;
    int i;
    for (i = 1; i < pos - 1; i++) {
      temp = temp->next;
    }
    node* dlt = temp->next;
    temp->next = dlt->next;
    free(dlt);
  }
  return head;
}
