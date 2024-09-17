package main

import (
	"fmt"
	"strings"
)

// Book represents a book with a title
type Book struct {
	Title string
}

func Do_A2() {
	// Question 1: Quick Sort
	fmt.Println("Question 1: Quick Sort")
	arr := []int{20, 33, 41, 55, 56, 60, 61, 70}
	fmt.Println("Original array:", arr)
	quickSort(arr, 0, len(arr)-1, 0)
	fmt.Println("Final sorted array (descending):", arr)

	// Question 2: Insertion Sort
	fmt.Println("\nQuestion 2: Insertion Sort")
	books := []Book{
		{Title: "To Kill a Mockingbird"},
		{Title: "Pride and Prejudice"},
		{Title: "1984"},
		{Title: "The Great Gatsby"},
		{Title: "Animal Farm"},
	}
	fmt.Println("Original book order:")
	printBooks(books)
	insertionSort(books)
	fmt.Println("\nFinal sorted book order:")
	printBooks(books)
}

// Quick Sort implementation
func quickSort(arr []int, low, high, depth int) {
	if low < high {
		indent := strings.Repeat("  ", depth)
		fmt.Printf("%sQuick Sort call: %v (low=%d, high=%d)\n", indent, arr[low:high+1], low, high)

		pi := partition(arr, low, high, depth)

		fmt.Printf("\n%sAfter partition: %v (pivot index=%d, pivot value=%d)\n", indent, arr, pi, arr[pi])

		quickSort(arr, low, pi-1, depth+1)
		quickSort(arr, pi+1, high, depth+1)

		fmt.Printf("%sAfter recursive calls: %v\n", indent, arr[low:high+1])
	}
}

func partition(arr []int, low, high, depth int) int {
	indent := strings.Repeat("  ", depth)
	pivot := arr[(low+high)/2]
	fmt.Printf("%sPartitioning with pivot %d: %v\n", indent, pivot, arr[low:high+1])

	i := low - 1
	j := high + 1
	for {
		for {
			i++
			if arr[i] <= pivot {
				break
			}
		}
		for {
			j--
			if arr[j] >= pivot {
				break
			}
		}
		if i >= j {
			fmt.Printf("%sPartition complete: %v\n", indent, arr[low:high+1])
			return j
		}
		fmt.Printf("%sSwapping %d and %d: ", indent, arr[i], arr[j])
		arr[i], arr[j] = arr[j], arr[i]
		fmt.Printf("%v\n", arr[low:high+1])
	}
}

// Insertion Sort implementation
func insertionSort(books []Book) {
	fmt.Println("Insertion Sort steps:")
	for i := 1; i < len(books); i++ {
		key := books[i]
		j := i - 1
		fmt.Printf("Step %d - Inserting '%s':\n", i, key.Title)
		fmt.Printf("  Before: ")
		printBooks(books)

		for j >= 0 && strings.Compare(books[j].Title, key.Title) > 0 {
			books[j+1] = books[j]
			j--
			fmt.Printf("  Shifting: ")
			printBooks(books)
		}
		books[j+1] = key

		fmt.Printf("  After:  ")
		printBooks(books)
		fmt.Println()
	}
}

func printBooks(books []Book) {
	for _, book := range books {
		fmt.Printf("%s, ", book.Title)
	}
	fmt.Println()
}
