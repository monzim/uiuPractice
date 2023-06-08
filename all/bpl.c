#include <stdio.h>
#include <string.h>

int main() {
  int t;
  scanf("%d", &t);

  while (t--) {
    char s[101];
    scanf("%s", s);

    int valid_bolls = 0;
    int total_over = 0;
    int i = 0;
    int length = strlen(s);

    while (i < length) {
      char output = s[i];

      if (output == 'N' || output == 'W' || output == 'D') {
        i++;
        continue;
      }

      valid_bolls++;
      i++;

      if (valid_bolls % 6 == 0) {
        total_over++;
      }
    }

    if (total_over > 0) {
      if (total_over == 1) {
        printf("%d OVER ", total_over);
      } else {
        printf("%d OVERS ", total_over);
      }
    }
    if (valid_bolls != 0) {
      if (valid_bolls > 0 && valid_bolls < 6) {
        if (valid_bolls == 1) {
          printf("%d BALL\n", valid_bolls);
        } else {
          printf("%d BALLS\n", valid_bolls);
        }
      } else {
        if (valid_bolls % 6 == 1 && valid_bolls % 6 != 0) {
          printf("%d BALL\n", valid_bolls % 6);
        } else {
          if (valid_bolls % 6 != 0) {
            printf("%d BALLS\n", valid_bolls % 6);
          } else {
            printf("\n");
          }
        }
      }
    }
  }

  return 0;
}
