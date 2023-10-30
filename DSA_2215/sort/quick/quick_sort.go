package main

import "fmt"

type SortType int

const (
	Ascending SortType = iota
	Descending
)

func quickSort(arr []int, sortType SortType) []int {
	if len(arr) < 2 {
		return arr
	}

	pivot := arr[len(arr)/2]
	left := make([]int, 0)
	right := make([]int, 0)

	for _, value := range arr {
		if value < pivot {
			left = append(left, value)
		} else if value > pivot {
			right = append(right, value)
		}
	}

	left = quickSort(left, sortType)
	right = quickSort(right, sortType)

	result := append(left, pivot)
	result = append(result, right...)

	if sortType == Descending {
		// Reverse the result for descending order
		for i, j := 0, len(result)-1; i < j; i, j = i+1, j-1 {
			result[i], result[j] = result[j], result[i]
		}
	}

	return result
}

func useMe() {
	arr := []int{64, 25, 12, 22, 11}
	sortType := Ascending // Change to Descending for descending
	sortedArray := quickSort(arr, sortType)
	fmt.Println("Sorted array:", sortedArray)
}
