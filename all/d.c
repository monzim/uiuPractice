/*
D - Mike and strings
Mike has n strings s1, s2, ..., sn each consisting of lowercase English letters. In one move he can choose a string si,
erase the first character and append it to the end of the string. For example, if he has the string "coolmike", in one
move he can transform it into the string "oolmikec".

Now Mike asks himself: what is minimal number of moves that he needs to do in order to make all the strings equal?

Input
The first line contains a single integer n (50) — the number of strings.
This is followed by n lines which contain a string each. The i-th line corresponding to string si. Lengths of strings
are equal. Lengths of each string is positive and don't exceed 50.

Output
Print the minimal number of moves Mike needs in order to make all the strings equal or print  - 1 if there is no
solution.

Sample 1:
4
xzzwo
zwoxz
zzwox
xzzwo


Output:
5

Sample 2:
2
molzv
lzvmo

Output:
2


Sample 3:
3
kc
kc
kc

Output:
0

Sample 4:
3
aa
aa
ab

Output:
-1

Note: In the first sample testcase the optimal scenario is to perform operations in such a way as to transform all
strings into "zwoxz".

*/

#include <stdio.h>
#include <string.h>

#define MAX_N 50
#define MAX_LEN 50

int main() {
  int n, i, j, k, moves = 0;
  char strings[MAX_N][MAX_LEN + 1], base[MAX_LEN + 1];
  int freq[MAX_LEN][26];

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%s", strings[i]);
  }

  strcpy(base, strings[0]);
  for (i = 1; i < n; i++) {
    if (strcmp(strings[i], base) != 0) {
      printf("-1\n");
      return 0;
    }
  }

  for (i = 0; i < strlen(base); i++) {
    for (j = 0; j < 26; j++) {
      freq[i][j] = 0;
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < strlen(strings[i]); j++) {
      freq[j][strings[i][j] - 'a']++;
    }
  }

  for (i = 0; i < strlen(base); i++) {
    int min_moves = n;
    for (j = 0; j < 26; j++) {
      int cur_moves = 0;
      for (k = 0; k < 26; k++) {
        cur_moves += freq[i][(j + k) % 26];
      }
      if (cur_moves < min_moves) {
        min_moves = cur_moves;
      }
    }
    moves += min_moves;
  }

  printf("%d\n", moves);

  return 0;
}
