class HashTable {
  Map<int, int> _table = {};

  void insert(int key, int value) {
    _table[key] = value;
  }

  int? search(int key) {
    return _table[key];
  }
}

void useMe() {
  HashTable ht = HashTable();
  ht.insert(1, 10);
  ht.insert(2, 20);
  int targetKey = 2;
  int? value = ht.search(targetKey);
  if (value != null) {
    print("Value for key $targetKey is $value");
  } else {
    print("Key $targetKey not found in the hash table");
  }
}

void main() {
  useMe();
}
