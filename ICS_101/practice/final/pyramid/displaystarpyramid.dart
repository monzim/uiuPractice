import 'dart:io';

void main() {
  int n;

  stdout.write('Enter the number of rows: ');
  n = int.parse(stdin.readLineSync() ?? '0');

  for (int i = 0; i < n; i++) {
    print('\n');
    for (int j = 0; j < n - 1; j++) stdout.write(' ');
    for (int j = 0; j < 2 * i - 1; j++) stdout.write('*');
  }
}
