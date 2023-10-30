class Stack {
  List<int> _items = [];

  void push(int item) {
    _items.add(item);
  }

  int? pop() {
    if (_items.isEmpty) {
      return null;
    }
    return _items.removeLast();
  }

  int find(int item) {
    for (int i = _items.length - 1; i >= 0; i--) {
      if (_items[i] == item) {
        return i;
      }
    }
    return -1;
  }

  void remove(int item) {
    int index = find(item);
    if (index != -1) {
      _items.removeAt(index);
    }
  }

  int last() {
    if (_items.isEmpty) {
      return -1;
    }
    return _items.last;
  }

  int first() {
    if (_items.isEmpty) {
      return -1;
    }
    return _items.first;
  }

  void display() {
    for (int i = _items.length - 1; i >= 0; i--) {
      print("${_items[i]} ");
    }
    print("");
  }
}

void useMe() {
  var stack = Stack();
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.display();

  var item = stack.pop();
  if (item != null) {
    print("Popped item: $item");
  }

  stack.remove(2);
  print("Stack after removing 2: ");
  stack.display();

  print("Index of 1: ${stack.find(1)}");
  print("Last item: ${stack.last()}");
  print("First item: ${stack.first()}");
}

void main() {
  useMe();
}
