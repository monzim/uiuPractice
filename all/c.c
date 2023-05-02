/*
After the lessons n groups of schoolchildren went outside and decided to visit Polycarpus to celebrate his
        birthday.We know that the i -
    th group consists of si friends(1 ≤ si ≤ 4),
    and they want to go to Polycarpus together.They decided to get there by taxi
            .Each car can carry at most four passengers.What minimum number of taxiK will the children need
        if all members of each group should ride in the same taxi(but one taxi can take more than one group)
    ?
Input
    The first line contains a single integer n(1 ≤ n ≤ 105) — the number of groups of children.
    The second line contains n integers s1, s2, ..., sn(1 ≤ si ≤ 4), where si is the number of children in the i -
    th group.

Output
    Print the single number — the minimum number of taxis necessary to drive all children to Polycarpus.

Sample 1:
    Input:
    5
    1 2 4 3 3
    Output:
    4
    Sample 2:
    Input:
    8
    2 3 4 4 2 1 3 1
    Output:
    5

Note
    In the first test we can sort the children into four taxiK like this:

the third group (consisting of four children),
the fourth group (consisting of three children),
the fifth group (consisting of three children),
the first and the second group (consisting of one and two children, correspondingly).
There are other ways to sort the groups into four taxiK.
*/

#include <stdio.h>

int main() {
  int num, single, k[5] = {0};
  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    scanf("%d", &single);
    k[single]++;
  }
  int taxiK = k[4] + k[3] + (k[2] + 1) / 2;
  if (k[1] > k[3]) {
    taxiK += (k[1] - k[3] + 3) / 4;
  }
  printf("%d\n", taxiK);
  return 0;
}

// #include <stdio.h>

// int main() {
//   int n;
//   scanf("%d", &n);

//   int count[5] = {0};

//   for (int i = 0; i < n; i++) {
//     int size;
//     scanf("%d", &size);
//     count[size]++;
//   }

//   int taxiK = count[4] + count[3];
//   if (count[1] >= count[3]) {
//     count[1] -= count[3];
//     taxiK += count[3];
//     taxiK += (count[2] + 1) / 2;
//     taxiK += (count[1] + 3) / 4;
//   } else {
//     taxiK += count[1];
//   }

//   printf("%d\n", taxiK);

//   return 0;
// }
