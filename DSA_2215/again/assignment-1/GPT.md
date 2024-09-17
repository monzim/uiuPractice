# Mid Assessment Assignment 1: Summer 2024

**Course Code:** CSE 2215  
**Course Title:** Data Structures and Algorithms 1  
**Total Marks:** 10  
**Deadline:** 18.09.24

---

## Question 1

### Apply Quick Sort to the given array to sort it in descending order. You must demonstrate each step of the simulation in detail. Choose the pivot strategy that is most likely to achieve the best-case scenario for the following array:

**Array:** 20, 33, 41, 55, 56, 60, 61, 70

### Answer:

To solve this problem, we will use **Quick Sort** with a pivot strategy that selects the middle element to achieve the best case. Our array is:

**Array:** 20, 33, 41, 55, 56, 60, 61, 70

We need to sort it in descending order, so the array should end up in the form:

**Sorted Array:** 70, 61, 60, 56, 55, 41, 33, 20

#### Steps:

1. **Initial Array:**  
   20, 33, 41, 55, 56, 60, 61, 70  
   Pivot = 55 (middle element)

2. **Partitioning Step:**

   - Greater than 55: 70, 61, 60, 56
   - Equal to pivot: 55
   - Less than 55: 20, 33, 41

3. **Recursive Step on Greater than 55:**
   Subarray: 70, 61, 60, 56  
   Pivot = 60

   - Greater than 60: 70, 61
   - Equal to pivot: 60
   - Less than 60: 56

4. **Recursive Step on 70, 61:**  
   Subarray: 70, 61  
   Pivot = 61

   - Greater than 61: 70
   - Equal to pivot: 61  
     Sorted subarray: 70, 61

5. **Recursive Step on 20, 33, 41:**  
   Subarray: 20, 33, 41  
   Pivot = 33
   - Greater than 33: 41
   - Equal to pivot: 33
   - Less than 33: 20  
     Sorted subarray: 41, 33, 20

#### Final Sorted Array:

70, 61, 60, 56, 55, 41, 33, 20

---

## Question 2

### Imagine you are a librarian who needs to organize a small stack of returned books on a shelf. The books are initially in a random order. You decide to use the Insertion Sort algorithm to sort the books by their titles.

Given that you often add one book at a time to the already sorted section of the shelf, explain how the time complexity of Insertion Sort makes it a suitable choice for this task. Additionally, compare its performance in the best-case scenario versus the worst-case scenario when sorting the stack of books. Provide examples to illustrate your explanation.

### Answer:

Insertion Sort works by taking each element (book) and placing it into its correct position in a sorted part of the array (shelf).

#### Time Complexity:

- **Best Case:** If the books are already sorted, the time complexity is **O(n)** because it only compares each element once.
- **Worst Case:** If the books are in reverse order, the time complexity is **O(n²)** because every new book has to be compared and shifted past all the previously sorted books.

#### Example:

Let's say we have books titled by their first letter: [D, A, E, C, B]

- **Initial array (unsorted):** D, A, E, C, B
- **Step 1:** Compare A with D, A is smaller, so swap. Sorted so far: [A, D]
- **Step 2:** E is greater than D, so leave it. Sorted so far: [A, D, E]
- **Step 3:** C is less than E, swap it with D. Sorted so far: [A, C, D, E]
- **Step 4:** B is less than C, swap it with A. Final array: [A, B, C, D, E]

In the **best case**, where the books are almost sorted, Insertion Sort works in linear time. In the **worst case**, if the books are in the reverse order, it works in quadratic time.

---

## Question 3

### In a magic land, numbers are sorted in a special order. You need to find the magic number 77 in the following sorted list of numbers: [1, 4, 7, 13, 26, 37, 50, 62, 77, 88, 99]. You can use either linear search or binary search. But beware, if you use more than 3 steps, the spell will break! Which search method will you choose, and can you find the number in 3 steps or less?

### Answer:

We should choose **Binary Search** as it is faster and more efficient for sorted arrays, with a time complexity of **O(log n)**. The goal is to find the number 77 in 3 steps or less.

#### Steps for Binary Search:

1. Start with the middle element: 50 (middle of the array).

   - 77 > 50, so look at the right half.

2. Now, the new middle element is 77 (middle of the right half).
   - 77 == 77, so we have found the number in just **2 steps**.

Thus, we can find the number 77 in 2 steps using **Binary Search**, which is less than the required 3 steps.

---

## Question 4

### Find the memory location of A[15][45] if loc(A[5][15])=4500. Assume row-wise memory is allocated in the double type array A[60][60], where each double data is 8 bytes.

### Answer:

To find the memory location, we can use the formula for row-major order:

**Formula:**  
loc(A[i][j]) = loc(A[base_row][base_column]) + ((i - base*row) * number*of_columns + (j - base_column)) * size_of_element

Given:

- loc(A[5][15]) = 4500
- Base row = 5, base column = 15
- Number of columns = 60
- Size of each element = 8 bytes

Now, applying for A[15][45]:

```
loc(A[15][45]) = 4500 + ((15 - 5) * 60 + (45 - 15)) * 8
               = 4500 + (10 * 60 + 30) * 8
               = 4500 + (600 + 30) * 8
               = 4500 + 630 * 8
               = 4500 + 5040
               = 9540
```

Thus, the memory location of A[15][45] is **9540**.

---

## Question 5

### Consider the following two functions and determine the time complexity of both:

i. \( f(n) = 2n + 3 \)
ii. \( f(n) = 3n^2 + 2n + 1 \)

### Answer:

**(i) \( f(n) = 2n + 3 \):**

- The dominant term here is **2n**.
- Time complexity = **O(n)**

**(ii) \( f(n) = 3n^2 + 2n + 1 \):**

- The dominant term here is **3n²**.
- Time complexity = **O(n²)**

---

## Question 6

### Prove the following:

i. The running time of \( f(n) = n + 5n \) is \( \Omega(n) \).
ii. The running time of \( f(n) = 5n^3 \) is \( O(n^3) \).
iii. The running time of \( f(n) = n + 7n \) is \( \Theta(n) \).

### Answer:

**(i) \( f(n) = n + 5n \):**

- \( f(n) \) grows linearly, so it is bounded below by a linear function.
- Therefore, \( f(n) = \Omega(n) \).

**(ii) \( f(n) = 5n^3 \):**

- The dominant term is \( n^3 \).
- Therefore, \( f(n) = O(n^3) \).

**(iii) \( f(n) = n + 7n \):**

- Since both the lower and upper bounds of the function are linear, \( f(n) = \Theta(n) \).
