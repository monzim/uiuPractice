Certainly! I'll solve the assignment as if writing on an A4 paper, using Markdown format. I'll include the full question before each answer and use visualizations where appropriate. Let's begin:

```markdown
# CSE 2215: Data Structures and Algorithms 1

## Mid Assessment Assignment 1: Summer 2024

### Total Marks: 10

### Deadline: 18.09.24

---

## Question 1

Apply Quick Sort to the given array to sort it in Descending order. You must demonstrate each step of the simulation in detail. Choose the pivot strategy that is most likely to achieve the best-case scenario for the following array:

Array: 20 33 41 55 56 60 61 70

### Answer:

To achieve the best-case scenario for Quick Sort, we should choose a pivot that divides the array into two equal (or nearly equal) parts. In this case, the median of the array would be the best choice. Since the array is already sorted in ascending order, we can choose the middle element as our pivot.

Let's apply Quick Sort using the middle element as the pivot:

Step 1: Choose the middle element (56) as the pivot.
```

[20, 33, 41, 55, 56, 60, 61, 70]
^
pivot

```

Step 2: Partition the array around the pivot.
- Elements greater than 56 go to the left.
- Elements smaller than 56 go to the right.
- The pivot stays in place.

```

[70, 61, 60, 56, 55, 41, 33, 20]
^
pivot

```

Step 3: Recursively apply Quick Sort to the left and right subarrays.

Left subarray: [70, 61, 60]
- Choose 61 as pivot
```

[70, 61, 60]
^
pivot

```
After partitioning:
```

[70, 61, 60]
^
pivot

```
No further sorting needed for this subarray.

Right subarray: [55, 41, 33, 20]
- Choose 41 as pivot
```

[55, 41, 33, 20]
^
pivot

```
After partitioning:
```

[55, 41, 33, 20]
^
pivot

```
No further sorting needed for this subarray.

Final sorted array in descending order:
```

[70, 61, 60, 56, 55, 41, 33, 20]

```

The best-case scenario was achieved by choosing the median as the pivot, resulting in balanced partitions and minimal recursive calls.

---

## Question 2

Imagine you are a librarian who needs to organize a small stack of returned books on a shelf. The books are initially in a random order. You decide to use the Insertion Sort algorithm to sort the books by their titles.

Given that you often add one book at a time to the already sorted section of the shelf, explain how the time complexity of Insertion Sort makes it a suitable choice for this task. Additionally, compare its performance in the best-case scenario versus the worst-case scenario when sorting the stack of books. Provide examples to illustrate your explanation.

### Answer:

Insertion Sort is indeed a suitable choice for organizing books on a shelf, especially when new books are frequently added. Here's why:

1. Incremental sorting: Insertion Sort works by building the final sorted array one element at a time. This aligns perfectly with the scenario of adding one book at a time to an already sorted section.

2. In-place sorting: The algorithm sorts the books directly on the shelf without requiring additional space, which is practical for a librarian.

3. Adaptive: Insertion Sort performs well on partially sorted arrays, which is often the case in a library where books might be somewhat organized already.

Time Complexity:
- Best-case scenario: O(n)
- Average-case scenario: O(n²)
- Worst-case scenario: O(n²)

Best-case scenario:
When the books are already sorted or nearly sorted, Insertion Sort performs exceptionally well.

Example: Adding a new book "Brave New World" to an already sorted shelf:
```

1. "1984"
2. "Animal Farm"
3. "Lord of the Flies"
4. "To Kill a Mockingbird"

New book: "Brave New World"

```
In this case, the algorithm only needs to compare "Brave New World" with "To Kill a Mockingbird" and then insert it in its correct position. This requires only one comparison and one insertion, resulting in O(1) time for adding a single book to a sorted list.

Worst-case scenario:
When the books are in reverse order or when each new book needs to be inserted at the beginning of the sorted section.

Example: Sorting books that are in reverse alphabetical order:
```

Initial order:

1. "To Kill a Mockingbird"
2. "Lord of the Flies"
3. "Brave New World"
4. "Animal Farm"
5. "1984"

```
In this case, each book (except the first) needs to be compared with all the books before it and moved to the beginning. This results in approximately n²/2 comparisons and movements, leading to O(n²) time complexity.

Despite its quadratic worst-case time complexity, Insertion Sort remains efficient for small datasets (like a small stack of books) and performs exceptionally well when the data is partially sorted or when new elements are continuously added to an already sorted list. These characteristics make it an excellent choice for a librarian organizing books on a shelf.

---

## Question 3

In a magic land, numbers are sorted in a special order. You need to find the magic number 77 in the following sorted list of numbers: [1, 4, 7, 13, 26, 37, 50, 62, 77, 88, 99]. You can use either linear search or binary search. But beware, if you use more than 3 steps, the spell will break! Which search method will you choose, and can you find the number in 3 steps or less?

### Answer:

To find the magic number 77 in 3 steps or less, we should use Binary Search. Here's why:

1. The list is already sorted, which is a prerequisite for Binary Search.
2. Binary Search can find any element in a sorted list of n elements in at most log₂(n) steps.
3. In this case, we have 11 elements, and log₂(11) ≈ 3.46, which means we can find any element in at most 4 steps.

Let's apply Binary Search to find 77:

Step 1: Start with the middle element.
```

[1, 4, 7, 13, 26, 37, 50, 62, 77, 88, 99]
^
middle (37)

```
37 < 77, so we search the right half.

Step 2: Look at the middle of the right half.
```

[1, 4, 7, 13, 26, 37, 50, 62, 77, 88, 99]
^
middle (62)

```
62 < 77, so we search the right half again.

Step 3: Look at the middle of the remaining right half.
```

[1, 4, 7, 13, 26, 37, 50, 62, 77, 88, 99]
^
middle (77)

```
We found 77!

Therefore, we can find the magic number 77 in exactly 3 steps using Binary Search, successfully completing the task without breaking the spell.

---

## Question 4

Find the memory location of A[15][45] if loc(A[5][15])=4500. Assume row-wise memory is allocated in the double type array A[60][60], where each double data is 8 bytes.

### Answer:

To find the memory location of A[15][45], we'll use the formula for row-major order memory allocation:

```

loc(A[i][j]) = base_address + [(i - lower_bound_i) * n + (j - lower_bound_j)] \* size_of_element

````

Where:
- base_address is the starting address of the array
- lower_bound_i and lower_bound_j are the lower bounds of the array indices (usually 0)
- n is the number of columns
- size_of_element is the size of each element in bytes

Given:
- loc(A[5][15]) = 4500
- A[60][60] is a double type array
- Each double data is 8 bytes
- Array indices start from 0 (lower bounds are 0)

Step 1: Find the base address of the array.
Using the formula for A[5][15]:
4500 = base_address + [(5 - 0) * 60 + (15 - 0)] * 8
4500 = base_address + [300 + 15] * 8
4500 = base_address + 2520
base_address = 4500 - 2520 = 1980

Step 2: Calculate the memory location of A[15][45]
loc(A[15][45]) = 1980 + [(15 - 0) * 60 + (45 - 0)] * 8
               = 1980 + [900 + 45] * 8
               = 1980 + 945 * 8
               = 1980 + 7560
               = 9540

Therefore, the memory location of A[15][45] is 9540.

---

## Question 5

Consider the following two functions and determine the time complexity of both:

i.
```c
void function1(int n) {
    int i, j, k;
    for (i = n/2; i <= n; i++)
        for (j = 2; j <= n; j = j * 2)
            for (k = 1; k <= n; k = k * 2)
                printf("%d", n);
}
````

ii.

```c
int function2(int n) {
    int count = 0;
    for (int i = 1; i <= n; i *= 2) {
        for (int j = 1; j <= n; j++) {
            count++;
        }
    }
    return count;
}
```

### Answer:

i. Time complexity of function1:

Let's analyze each loop:

1. Outer loop (i):

   - Starts from n/2 and goes up to n
   - Runs approximately n/2 times
   - O(n)

2. Middle loop (j):

   - Starts from 2 and doubles each time until it reaches n
   - Runs log₂(n) times
   - O(log n)

3. Inner loop (k):
   - Similar to the j loop, doubles each time until it reaches n
   - Runs log₂(n) times
   - O(log n)

The total time complexity is the product of these three loops:
O(n) _ O(log n) _ O(log n) = O(n log² n)

Therefore, the time complexity of function1 is O(n log² n).

ii. Time complexity of function2:

Let's analyze each loop:

1. Outer loop (i):

   - Starts from 1 and doubles each time until it reaches n
   - Runs log₂(n) times
   - O(log n)

2. Inner loop (j):
   - Runs from 1 to n for each iteration of the outer loop
   - O(n)

The total time complexity is the product of these two loops:
O(log n) \* O(n) = O(n log n)

Therefore, the time complexity of function2 is O(n log n).

---

## Question 6

Prove the following:

i. The running time of f(n) = 1/3 n³ - 5n² is Ω(n³).
ii. The running time of f(n) = 5n² - 3 is O(n²).
iii. The running time of f(n) = 1/2 n² - 7n is θ(n²).

### Answer:

i. Prove that f(n) = 1/3 n³ - 5n² is Ω(n³)

To prove f(n) is Ω(n³), we need to show that there exist positive constants c and n₀ such that f(n) ≥ c \* n³ for all n ≥ n₀.

Let's choose c = 1/6 and n₀ = 30.

For n ≥ 30:
f(n) = 1/3 n³ - 5n²
≥ 1/3 n³ - 5n³/30 (since n² ≤ n³/30 for n ≥ 30)
= 1/3 n³ - 1/6 n³
= 1/6 n³
= c \* n³

Therefore, f(n) = 1/3 n³ - 5n² is Ω(n³).

ii. Prove that f(n) = 5n² - 3 is O(n²)

To prove f(n) is O(n²), we need to show that there exist positive constants c and n₀ such that f(n) ≤ c \* n² for all n ≥ n₀.

Let's choose c = 6 and n₀ = 1.

For all n ≥ 1:
f(n) = 5n² - 3
< 5n² + n² (since -3 < n² for n ≥ 1)
= 6n²
= c \* n²

Therefore, f(n) = 5n² - 3 is O(n²).

iii. Prove that f(n) = 1/2 n² - 7n is θ(n²)

To prove f(n) is θ(n²), we need to show that f(n) is both O(n²) and Ω(n²).

First, let's prove f(n) is O(n²):
Choose c₁ = 1 and n₁ = 14.

For n ≥ 14:
f(n) = 1/2 n² - 7n
≤ 1/2 n²
< n²
= c₁ \* n²

Now, let's prove f(n) is Ω(n²):
Choose c₂ = 1/4 and n₂ = 28.

For n ≥ 28:
f(n) = 1/2 n² - 7n
≥ 1/2 n² - 1/4 n² (since 7n ≤ 1/4 n² for n ≥ 28)
= 1/4 n²
= c₂ \* n²

Since f(n) is both O(n²) and Ω(n²), we can conclude that f(n) = 1/2 n² - 7n is θ(n²).
