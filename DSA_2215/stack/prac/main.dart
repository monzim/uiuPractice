import 'dart:io';

void main() {
  Stack<int> stack = Stack();

  for (;;) {
    switch (menu()) {
      case 1:
        print('Enter value: ');
        stack.push(int.parse(stdin.readLineSync()!));
        break;
      case 2:
        print('Pop: ${stack.pop()}');
        break;
      case 3:
        print('Peek: ${stack.peek()}');
        break;
      case 4:
        print('Is Empty: ${stack.isEmpty()}');
        break;
      case 5:
        print('Size: ${stack.size()}');
        break;
      case 6:
        print('Stack: ${stack._data}');
        break;
      case 7:
        return;
      default:
        print('Invalid choice');
    }
  }
}

int menu() {
  print('1. Push');
  print('2. Pop');
  print('3. Peek');
  print('4. Is Empty');
  print('5. Size');
  print('6. Display');
  print('7. Exit');

  print('Enter your choice: ');
  return int.parse(stdin.readLineSync()!);
}

class Stack<T> {
  List<T> _data = [];

  void push(T value) {
    _data.add(value);
  }

  T? pop() {
    if (_data.isEmpty) {
      return null;
    }

    return _data.removeLast();
  }

  T? peek() {
    if (_data.isEmpty) {
      return null;
    }
    return _data.last;
  }

  bool isEmpty() {
    return _data.isEmpty;
  }

  int size() {
    return _data.length;
  }
}
