import 'dart:math';

class Node {
  int value;
  Node? next;
  Node? prev;

  Node(this.value, [this.next, this.prev]);
}

class LinkedList {
  Node? head;

  void addSorted(int value) {
    if (head == null || value < head!.value) {
      head = Node(value, head);
    } else {
      Node? current = head;
      while (current!.next != null && current.next!.value <= value) {
        current = current.next;
      }
      current.next = Node(value, current.next, current);
    }
  }

  void addAllSorted(List<int> values) {
    for (int value in values) {
      addSorted(value);
    }
  }
}

void main() {
  LinkedList linkedList = LinkedList();

  int n = 10;
  List<int> randomList = [];

//
  for (int i = 0; i < n; i++) {
    linkedList.addSorted((Random().nextInt(10000)));
    // randomList.add(Random().nextInt(10000));
  }

  // linkedList.addAllSorted(randomList);
  Node? current = linkedList.head;
  while (current != null) {
    print(current.value);
    current = current.next;
  }
}
