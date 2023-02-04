import 'dart:io';
import 'dart:math';

int sum_digits(int n) {
  if (n == 0) return 0;
  return (n % 10) + sum_digits(n ~/ 10);
}

num reverse_digits(int n) {
  if (n < 10) return n;
  return (n % 10) * pow(10, (n.toString().length - 1)) +
      reverse_digits(n ~/ 10);
}

void main(List<String> args) {
  stdout.write('Enter a number: ');
  int n = int.parse(stdin.readLineSync() ?? '0');

  stdout.writeln('Sum: ${sum_digits(n)}');
  print(n);
  stdout.writeln('Reverse: ${reverse_digits(n)}');
}
