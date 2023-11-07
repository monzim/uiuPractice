import 'dart:math';

extension NodeValue on Node {
  int get value => this.data;
  int get possitionValue => this.data;
  int get nodeCost => this.data + (this.next?.data ?? 0);
}

class Node {
  int data;
  Node? next;

  Node(this.data);
}

class LinkedList {
  Node? head;

  void append(int data) {
    final newNode = Node(data);
    if (head == null) {
      head = newNode;
      return;
    }

    var current = head;
    while (current!.next != null) {
      current = current.next;
    }

    current.next = newNode;
  }

  void insert(int data, int position) {
    final newNode = Node(data);
    if (position == 0) {
      newNode.next = head;
      head = newNode;
      return;
    }

    var current = head;
    var index = 0;
    while (current != null) {
      if (index == position - 1) {
        newNode.next = current.next;
        current.next = newNode;
        return;
      }
      current = current.next;
      index++;
    }
  }

  void addTOEnd(int data) {
    final newNode = Node(data);
    if (head == null) {
      head = newNode;
      return;
    }

    var current = head;
    while (current!.next != null) {
      current = current.next;
    }

    current.next = newNode;
  }

  void addToSpecificPosition(int data, int position) {
    final newNode = Node(data);
    if (position == 0) {
      newNode.next = head;
      head = newNode;
      return;
    }

    var current = head;
    var index = 0;
    while (current != null) {
      if (index == position - 1) {
        newNode.next = current.next;
        current.next = newNode;
        return;
      }
      current = current.next;
      index++;
    }
  }

  void remove(int data) {
    if (head == null) return;
    if (head!.data == data) {
      head = head!.next;
      return;
    }

    var current = head;
    while (current!.next != null) {
      if (current.next!.data == data) {
        current.next = current.next!.next;
        return;
      }
      current = current.next;
    }
  }

  Node? find(int data) {
    var current = head;
    while (current != null) {
      if (current.data == data) {
        return current;
      }
      current = current.next;
    }
    return null;
  }

  void display() {
    var current = head;
    while (current != null) {
      print(current.data);
      current = current.next;
    }
  }

  void instertDataInSortedOrder(int data) {}
}

void main() {
  List<int> randomArray = [10, 4, 9, 7];
  // int limit = 10;

  // for (int i = 0; i < limit; i++) {
  //   randomArray.add(Random().nextInt(1000));
  // }

  var myList = LinkedList();

  // add random nodes to the list in such a way that the list is sorted in ascending order
  for (int i = 0; i < randomArray.length; i++) {
    myList.instertDataInSortedOrder(randomArray[i]);
//     final data = randomArray[i];

//     if (myList.head == null) {
//       myList.append(data);
//       continue;
//     }

// // get the current node
//     final current = data > myList.head!.data ? myList.head : myList.find(data);
//     print("current: $current");

//     //  add the first random number to the list
//     if (current == null) {
//       myList.append(data);
//       continue;
//     }

//     // insert in such a way so that the list is sorted in ascending order
//     myList.insert(data, randomArray.indexOf(data));

//     // add the last random number to the list
//     if (i == randomArray.length - 1) {
//       myList.addTOEnd(data);
//     }

//     // add random numbers to the list in such a way that the list is sorted in ascending order
//     myList.addToSpecificPosition(data, randomArray.indexOf(data));
  }

  // add limit nodes to the list

  myList.display();
}
