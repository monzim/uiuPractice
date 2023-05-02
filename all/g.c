// Grammy has an array of length n. She recently learned about the concept of greatest common divisor(GCD). Recall that
// the GCD of an array is the maximum integer d such that every element in the array is divisible by d. Grammy thinks
// that the GCD of an array should be as large as possible so that the array can be beautiful.

// You want to help Grammy to make her array beautiful, so you decided to do some (possibly zero) modulo operations on
// each of the elements in the array. In other words, for each operation, you can choose a number a (i <= i <=n) in the
// array and choose another integer x, and then replace å (å mod x) with x. Since Grammy does not want 0 to appear in
// her array, you cannot change å (å mod x) with 0.

// Now, your task is to calculate the maximum GCD of the array after several (possibly zero) modulo operations.

// Input:
// The first line contains an integer T (1 <= T <= 10^5), denoting the number of elements in the array.
// The second line contains n integers a1, a2, ..., an (1 <= ai <= 10^9), denoting the elements in the array.

// Output:
// Output a single integer, denoting the maximum GCD of the array after any number of modulo operations.

// Sample 1:
// 3
// 3 10 7
// Output:
// 3

#include <stdio.h>

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int n, a, g = 0;
  scanf("%d", &n);
  // Read the array elements and update GCD
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    g = gcd(g, a);
  }
  // Output the maximum GCD after any number of modulo operations
  printf("%d\n", g);
  return 0;
}
Dr. Bruce Banner hates his enemies (like others don't). As we all know, he can barely talk when he turns into the incredible Hulk. That's why he asked you to help him to express his feelings.

Hulk likes the Inception so much, and like that his feelings are complicated. They have n layers. The first layer is hate, second one is love, third one is hate and so on...

For example if n = 1, then his feeling is "I hate it" or if n = 2 it's "I hate that I love it", and if n = 3 it's "I hate that I love that I hate it" and so on.

Please help Dr. Banner.

Input: The only line of the input contains a single integer n (1 ≤ n ≤ 100) — the number of layers of love and hate.

Output: Print Dr.Banner's feeling in one line.

Sample 1:
Input:
1
Output:
I hate it

Sample 2:
Input:
2
Output:
I hate that I love it

Sample 3:
Input:
3
Output:
I hate that I love that I hate it