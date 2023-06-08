#include <math.h>
#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int flag = 0;
    for (int i = sqrt(n); i >= 1; i--) {
      if (n % i == 0) {
        int j = n / i;
        if ((j - i) == i) {
          printf("%d %d\n", j, i);
          flag = 1;
          break;
        }
      }
    }
    if (!flag) printf("-1\n");
  }
  return 0;
}