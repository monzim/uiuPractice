class Queue {
  List<int> _items = [];

  void add(int item) {
    _items.add(item);
  }

  int remove() {
    if (_items.isEmpty) {
      return -1;
    }
    return _items.removeAt(0);
  }

  void show() {
    for (var item in _items) {
      print("$item ");
    }
    print("");
  }

  int middle() {
    if (_items.isEmpty) {
      return -1;
    }
    int fast = 0;
    int slow = 0;
    while (fast < _items.length && fast + 1 < _items.length) {
      fast += 2;
      slow++;
    }
    return _items[slow];
  }

  bool search(int item) {
    return _items.contains(item);
  }
}

void useMe() {
  var queue = Queue();
  queue.add(1);
  queue.add(2);
  queue.add(3);
  queue.show();

  print("Middle element: ${queue.middle()}");

  print("Searching for 2: ${queue.search(2)}");

  var item = queue.remove();
  if (item != -1) {
    print("Removed item: $item");
  }

  queue.show();
}

void main() {
  useMe();
}
