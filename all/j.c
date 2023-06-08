Grammy has a big picture with 
�
+
1
n+1 rows and 
�
+
1
m+1 columns. Rows are numbered from 
1
1 to 
�
+
1
n+1 and columns are numbered from 
1
1 to 
�
+
1
m+1.

Grammy decides to color this picture in a special way. For the 
�
i-th row, Grammy will color the leftmost 
�
j (
1
≤
�
≤
�
1≤j≤m) cells black with probability 
�
�
,
�
p 
i,j
​
 . For the 
�
j-th column, Grammy will color the topmost 
�
i (
1
≤
�
≤
�
1≤i≤n) cells black with probability 
�
�
,
�
q 
i,j
​
 . Operations are independent, and a cell could be colored more than once.

Let us define the beauty value as the number of maximal orthogonally connected regions of the same color. Before Grammy finishes her coloring, she wants to know the expected number of regions on the picture. Please calculate the expected beauty value of the picture for her.

Two cells 
�
x and 
�
y are in the same orthogonally connected region if and only if they satisfy the following constraints:

They have the same color.
�
x shares an edge with 
�
y or 
�
x shares an edge with some cell 
�
z while 
�
y and 
�
z are in the same orthogonally connected region.