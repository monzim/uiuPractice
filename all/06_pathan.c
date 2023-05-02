/*
In a movie festival
�
n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies you
can watch entirely?

Input

The first input line has an integer
�
n: the number of movies.

After this, there are
�
n lines that describe the movies. Each line has two integers
�
a and
�
b: the starting and ending times of a movie.

Output

Print one integer: the maximum number of movies.

Constraints
1 <= n <= 2.10^5
1 <= a < b <= 10^9
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int start;
  int end;
} MovieSchema;

int setK(const void *a, const void *b) {
  MovieSchema *m1 = (MovieSchema *)a;
  MovieSchema *m2 = (MovieSchema *)b;

  if (m1->end < m2->end) {
    return -1;
  } else if (m1->end > m2->end) {
    return 1;
  } else {
    return 0;
  }
}
int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);

  MovieSchema moive[n];
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &moive[i].start, &moive[i].end);
  }

  qsort(moive, n, sizeof(MovieSchema), setK);

  int count = 1;
  int end = moive[0].end;
  for (int i = 1; i < n; i++) {
    if (moive[i].start >= end) {
      count++;
      end = moive[i].end;
    }
  }

  printf("%d ", count);

  return 0;
}
