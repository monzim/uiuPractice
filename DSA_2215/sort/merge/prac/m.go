package main

import "fmt"

// // Example use
// unsortedList := []float64{38, 27, 43, 3, 9, 82, 10}

// fmt.Println("Unsorted List:", unsortedList)

// ascendingSorted := mergeSort(unsortedList, Ascending)
// descendingSorted := mergeSort(unsortedList, Descending)

// fmt.Println("Ascending Sorted List:", ascendingSorted)
// fmt.Println("Descending Sorted List:", descendingSorted)

func merge(left, right []string) []string {
	result := make([]string, 0, len(left)+len(right))
	l, r := 0, 0

	for l < len(left) && r < len(right) {
		if left[l] < right[r] {
			result = append(result, left[l])
			l++
		} else {
			result = append(result, right[r])
			r++
		}
	}

	result = append(result, left[l:]...)
	result = append(result, right[r:]...)

	return result
}

func mergeSort(arr []string) []string {
	if len(arr) <= 1 {
		return arr
	}

	mid := len(arr) / 2
	left := mergeSort(arr[:mid])
	right := mergeSort(arr[mid:])

	return merge(left, right)
}

func main() {
	stringSlice := []string{"cherry", "grape", "date", "apple", "banana"}
	sortedStrings := mergeSort(stringSlice)
	fmt.Println(sortedStrings)
}
