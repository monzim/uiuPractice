package main

import "fmt"

// // Example use
// unsortedList := []float64{38, 27, 43, 3, 9, 82, 10}

// fmt.Println("Unsorted List:", unsortedList)

// ascendingSorted := mergeSort(unsortedList, Ascending)
// descendingSorted := mergeSort(unsortedList, Descending)

// fmt.Println("Ascending Sorted List:", ascendingSorted)
// fmt.Println("Descending Sorted List:", descendingSorted)

type SortOrder int

const (
	Ascending SortOrder = iota
	Descending
)

func merge(left, right []float64, order SortOrder) []float64 {
	result := make([]float64, 0, len(left)+len(right))
	l, r := 0, 0

	for l < len(left) && r < len(right) {
		if (order == Ascending && left[l] < right[r]) ||
			(order == Descending && left[l] > right[r]) {
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

func mergeSort(arr []float64, order SortOrder) []float64 {
	if len(arr) <= 1 {
		return arr
	}

	mid := len(arr) / 2
	left := mergeSort(arr[:mid], order)
	right := mergeSort(arr[mid:], order)

	return merge(left, right, order)
}

func main() {
	unsortedList := []float64{38, 27, 43, 3, 9, 82, 10}

	fmt.Println("Unsorted List:", unsortedList)

	ascendingSorted := mergeSort(unsortedList, Ascending)
	descendingSorted := mergeSort(unsortedList, Descending)

	fmt.Println("Ascending Sorted List:", ascendingSorted)
	fmt.Println("Descending Sorted List:", descendingSorted)
}
