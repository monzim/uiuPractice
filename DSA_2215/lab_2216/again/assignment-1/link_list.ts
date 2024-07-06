class NNode {
  value: number;
  next: NNode | null;

  constructor(value: number) {
    this.value = value;
    this.next = null;
  }
}

class LinkedList {
  head: NNode | null;

  constructor() {
    this.head = null;
  }

  insertAtFront(value: number): void {
    const newNNode = new NNode(value);
    newNNode.next = this.head;
    this.head = newNNode;
  }

  insertAtBack(value: number): void {
    const newNNode = new NNode(value);
    if (this.head === null) {
      this.head = newNNode;
      return;
    }
    let current = this.head;
    while (current.next !== null) {
      current = current.next;
    }
    current.next = newNNode;
  }

  insertInMiddle(value: number, after: number): void {
    const newNNode = new NNode(value);
    let current = this.head;
    while (current !== null && current.value !== after) {
      current = current.next;
    }
    if (current !== null) {
      newNNode.next = current.next;
      current.next = newNNode;
    }
  }

  deleteAtFront(): void {
    if (this.head !== null) {
      this.head = this.head.next;
    }
  }

  deleteAtBack(): void {
    if (this.head === null) {
      return;
    }
    if (this.head.next === null) {
      this.head = null;
      return;
    }
    let current = this.head;
    while (current.next && current.next.next !== null) {
      current = current.next;
    }
    current.next = null;
  }

  delete(value: number): void {
    if (this.head === null) {
      return;
    }
    if (this.head.value === value) {
      this.head = this.head.next;
      return;
    }
    let current = this.head;
    while (current.next !== null && current.next.value !== value) {
      current = current.next;
    }
    if (current.next !== null) {
      current.next = current.next.next;
    }
  }

  printList(): void {
    let current = this.head;
    const values: number[] = [];
    while (current !== null) {
      values.push(current.value);
      current = current.next;
    }
    console.log(values.join(" "));
  }
}

// Example usage
const ll = new LinkedList();
ll.printList(); // NULL

ll.insertAtFront(1);
ll.printList(); // 1

ll.insertAtBack(2);
ll.printList(); // 1 2

ll.insertInMiddle(7, 1);
ll.printList(); // 1 7 2

ll.insertAtFront(5);
ll.printList(); // 5 1 7 2

ll.insertAtBack(3);
ll.printList(); // 5 1 7 2 3

ll.deleteAtBack();
ll.printList(); // 5 1 7 2

ll.deleteAtFront();
ll.printList(); // 1 7 2

ll.delete(7);
ll.printList(); // 1 2
