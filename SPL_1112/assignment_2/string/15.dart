void main(List<String> args) {
  String str = "block and blog";
  List<String> list = str.split(" ");

  for (int i = list.length - 1; i >= 0; i--) {
    print(list[i]);
  }
}
