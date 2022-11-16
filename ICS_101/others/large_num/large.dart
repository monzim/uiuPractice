void main() {
  var list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
  var largest = list[0];
  var secondLargest = list[0];
  for (var i = 0; i < list.length; i++) {
    if (list[i] > largest) {
      secondLargest = largest;
      largest = list[i];
    } else if (list[i] > secondLargest) {
      secondLargest = list[i];
    }
  }
  print("Largest: $largest");
  print("Second Largest: $secondLargest");
}
