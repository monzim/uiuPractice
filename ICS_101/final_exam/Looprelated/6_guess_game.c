/* Important
Write a program (WAP) for the described scenario:
Player-1 picks a number X and Player-2 has to guess that number within N tries. For each
wrong guess by Player-2, the program prints “Wrong, N-1 Choice(s) Left!” If Player-2 at
any time successfully guesses the number, the program prints “Right, Player-2 wins!” and
terminates right away. Otherwise after the completion of N wrong tries, the program
prints “Player-1 wins!” and halts

Sample input
(X,N,n1, n2,..,nN)
Sample output
5
3
12 8 5
Wrong, 2 Choice(s) Left!
Wrong, 1 Choice(s) Left!
Right, Player-2 wins!
100
5
50 100
Wrong, 4 Choice(s) Left!
Right, Player-2 wins!
20
3
12 8 5
Wrong, 2 Choice(s) Left!
Wrong, 1 Choice(s) Left!
Wrong, 0 Choice(s) Left!
Player-1 wins!
*/

#include <stdio.h>

int main() {
  int x, guess, n;

  printf("Player-1, enter the number X: ");
  scanf("%d", &x);
  printf("Player-1, enter the number of tries N: ");
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    printf("Player-2, enter your guess: ");
    scanf("%d", &guess);

    if (guess == x) {
      printf("Right, Player-2 wins!\n");
      return 0;
    } else {
      printf("Wrong, %d choice(s) left!\n", n - i);
    }
  }

  printf("Player-1 wins!\n");

  return 0;
}
