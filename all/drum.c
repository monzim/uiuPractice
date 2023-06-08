/*
You are given an undirected connected graph with n n vertices and m
m edges. Each edge has an associated counter, initially equal to
0
0. In one operation, you can choose an arbitrary spanning tree and add any value
v
v to all edges of this spanning tree.

Determine if it's possible to make every counter equal to its target value
X
x
i
​modulo prime
p
p, and provide a sequence of operations that achieves it.

The first line contains three integers
�
n,
�
m, and
�
p — the number of vertices, the number of edges, and the prime modulus (
1
≤
�
≤
500
1≤n≤500;
1
≤
�
≤
1000
1≤m≤1000;
2
≤
�
≤
1
0
9
2≤p≤10
9
 ,
�
p is prime).

Next
�
m lines contain three integers
�
�
u
i
​
 ,
�
�
v
i
​
 ,
�
�
x
i
​
  each — the two endpoints of the
�
i-th edge and the target value of that edge's counter (
1
≤
�
�
,
�
�
≤
�
1≤u
i
​
 ,v
i
​
 ≤n;
0
≤
�
�
<
�
0≤x
i
​
 <p;
�
�
≠
�
�
u
i
​


=v
i
​
 ).

The graph is connected. There are no loops, but there may be multiple edges between the same two vertices.
*/

#include <stdio.h>

int main() {
  int n, m, p;
  scanf("%d %d %d", &n, &m, &p);

  int adj[n][n];
  int count[n][n];

  // initialize adjacency matrix and count matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      adj[i][j] = 0;
      count[i][j] = 0;
    }
  }

  // populate adjacency matrix and count matrix from input
  for (int i = 0; i < m; i++) {
    int u, v, x;
    scanf("%d %d %d", &u, &v, &x);
    adj[u - 1][v - 1] = 1;
    adj[v - 1][u - 1] = 1;
    count[u - 1][v - 1] = x;
    count[v - 1][u - 1] = x;
  }

  // Floyd-Warshall algorithm to compute shortest paths
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (adj[i][k] && adj[k][j]) {
          int new_count = count[i][k] + count[k][j];
          if (new_count < count[i][j]) {
            count[i][j] = new_count;
          }
        }
      }
    }
  }

  // compute sum of shortest path counts modulo p
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      sum = (sum + count[i][j]) % p;
    }
  }

  printf("%d\n", sum);

  return 0;
}
