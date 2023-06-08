/*

Outcome	Description
N	No ball
W	Wide ball
D	Dead ball
O	Out
0-6	Runs scored
As always, no ball, wide ball, and dead balls are not to be counted.
The input starts with an integer $T$($0 < T \le 100 $) denoting the number of test cases
    .Each case starts with a line containing a string $S$($0 < \texttt{Length of S} \le 100 $) representing the outcomes
of each ball.It is guaranteed that there is at least one legal Output For each test case print, the number of legal
balls and overs played. Make sure you are using the correct pluralization($\texttt{OVER} $ vs $\texttt{OVERS} $, and
$\texttt{BALL} $ vs $\texttt{BALLS} $). Output For each test case print, the number of legal balls and overs played
.Make sure you are using the correct pluralization($\texttt{OVER} $ vs $\texttt{OVERS} $, and $\texttt{BALL} $ vs
$\texttt{BALLS} $).ball.

Input
3 W123NW6WD64 444WO213 444

Output
1 OVER 1 OVER 1 BALL 3 BALLS

*/

#include <stdio.h>
#include <string.h>

int main() {
  int t;
  scanf("%d", &t);  // read the number of test cases

  while (t--) {  // iterate over all test cases
    char s[105];
    scanf("%s", s);  // read the outcomes of each ball

    int balls = 0;
    int overs = 0;
    int i = 0;

    while (s[i] != '\0') {  // iterate over all characters of the string

      // Outcome	Description
      // N	No ball
      // W	Wide ball
      // D	Dead ball
      // O	Out
      // 0-6	Runs scored
      // As always, no ball, wide ball, and dead balls are not to be counted.

      if (s[i] == 'N' || s[i] == 'W' || s[i] == 'D') {
        i++;
        continue;
      } else if (s[i] == 'O') {
        balls++;
        if (balls == 6) {
          overs++;
          balls = 0;
        }
      } else if (s[i] >= '0' && s[i] <= '6') {
        balls++;
        if (balls == 6) {
          overs++;
          balls = 0;
        }
      }

      // if (s[i] == 'N' || s[i] == 'W' || s[i] == 'D') {
      //     i++;
      //     continue;
      // } else if (s[i] == 'O') {
      //     balls++;
      //     if (balls == 6) {
      //     overs++;
      //     balls = 0;
      //     }
      // } else if (s[i] >= '0' && s[i] <= '6') {
      //     balls++;
      //     if (balls == 6) {
      //     overs++;
      //     balls = 0;
      //     }
      // }

      //   if (s[i] == 'W') {    // a wicket, so it's the end of an over
      //     overs++;
      //     balls = 0;
      //   } else if (s[i] >= '0' && s[i] <= '6') {  // a legal ball
      //     balls++;
      //     if (balls == 6) {  // six legal balls means the end of an over
      //       overs++;
      //       balls = 0;
      //     }
      //   }
      //   i++;
    }

    // output the result for this test case
    printf("%d ", overs);
    if (overs == 1) {
      printf("OVER ");
    } else {
      printf("OVERS ");
    }
    printf("%d ", balls);
    if (balls == 1) {
      printf("BALL\n");
    } else {
      printf("BALLS\n");
    }
  }

  return 0;
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//   int t;
//   scanf("%d", &t);  // read the number of test cases

//   while (t--) {  // iterate over all test cases
//     char s[105];
//     scanf("%s", s);  // read the outcomes of each ball

//     int balls = 0;
//     int overs = 0;
//     int i = 0;

//     while (s[i] != '\0') {  // iterate over all characters of the string
//       if (s[i] == 'W') {    // a wicket, so it's the end of an over
//         overs++;
//         balls = 0;
//       } else if (s[i] == 'O') {  // a legal ball
//         balls++;
//         if (balls == 6) {  // six legal balls means the end of an over
//           overs++;
//           balls = 0;
//         }
//       }
//       i++;
//     }

//     // output the result for this test case
//     printf("%d ", overs);
//     if (overs == 1) {
//       printf("OVER ");
//     } else {
//       printf("OVERS ");
//     }
//     printf("%d ", balls);
//     if (balls == 1) {
//       printf("BALL\n");
//     } else {
//       printf("BALLS\n");
//     }
//   }

//   return 0;
// }

// #include <stdio.h>
// #include <string.h>

// int main(int argc, char const *argv[]) {
//   int t;
//   scanf("%d", &t);
//   while (t--) {
//     char s[100];
//     scanf("%s", s);
//     int len = strlen(s);
//     int i = 0, j = 0, k = 0, l = 0;
//     while (i < len) {
//       if (s[i] == 'W') {
//         j++;
//         k = 0;
//       } else {
//         k++;
//         if (k == 6) {
//           j++;
//           k = 0;
//         }
//       }
//       i++;
//     }
//     if (k == 0) {
//       printf("%d OVER", j);
//     } else {
//       printf("%d OVER %d BALL", j, k);
//     }
//     if (j > 1) {
//       printf("S");
//     }
//     if (k > 1) {
//       printf("S");
//     }
//     printf(" \n");
//   }

//   return 0;
// }
