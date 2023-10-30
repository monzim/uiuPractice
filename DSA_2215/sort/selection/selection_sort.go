package main

import "fmt"

type SortType int

const (
	Ascending SortType = iota
	Descending
)

func selectionSort(arr []int, sortType SortType) {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		minIndex := i

		for j := i + 1; j < n; j++ {
			if (sortType == Ascending && arr[j] < arr[minIndex]) ||
				(sortType == Descending && arr[j] > arr[minIndex]) {
				minIndex = j
			}
		}

		if minIndex != i {
			arr[i], arr[minIndex] = arr[minIndex], arr[i]
		}
	}
}

func useMe() {
	arr := []int{64, 25, 12, 22, 11}
	sortType := Ascending // Change to Descending for descending
	selectionSort(arr, sortType)
	fmt.Println("Sorted array:", arr)
}
