## 5 (I)

The image contains pseudocode that resembles the **Selection Sort** algorithm. Let's analyze the time complexity step by step:

### Algorithm Breakdown:

1. The algorithm begins by determining the length of the array, `n`.
2. The outer loop runs from `j = 1` to `n-1`, making `n-1` iterations.
3. For each iteration of `j`, the algorithm finds the smallest element in the subarray from `j` to `n`:
   - An inner loop runs from `i = j+1` to `n`, comparing elements to find the smallest element.
   - The inner loop makes approximately `n - j` comparisons for each iteration of `j`.
4. After finding the smallest element, it swaps that element with the element at index `j`.

### Time Complexity:

- The outer loop runs `n-1` times.
- For each iteration of the outer loop, the inner loop makes `n - j` comparisons. In the worst case:
  - When `j = 1`, there are `n - 1` comparisons.
  - When `j = 2`, there are `n - 2` comparisons.
  - This pattern continues until `j = n-1`, where there is 1 comparison.

The total number of comparisons can be represented as the sum:
\[
(n-1) + (n-2) + \dots + 1 = \frac{n(n-1)}{2}
\]

Thus, the time complexity for the selection sort algorithm is:
\[
O(n^2)
\]

### Conclusion:

The time complexity of the given pseudocode is **O(n²)**, which is characteristic of the selection sort algorithm.

---

## 5 (II)

```c
int recFactorial(int n) {
    if (n == 1)
        return 1;
    else
        return n * recFactorial(n - 1);
}
```

### Time Complexity Analysis:

This recursive function computes the factorial of `n` by making a recursive call to itself with the argument `n-1` until `n` becomes 1, at which point the recursion stops.

#### Key observations:

- The function makes one recursive call at each step, decreasing `n` by 1.
- The base case is reached when `n == 1`.
- Therefore, the function makes exactly `n` recursive calls (one for each decrement from `n` to 1).

### Time Complexity:

Each recursive call performs a constant amount of work (i.e., multiplication and checking if `n == 1`), and there are `n` recursive calls in total.

Thus, the time complexity of the recursive factorial function is **O(n)**, as the number of recursive calls is proportional to the input size `n`.
