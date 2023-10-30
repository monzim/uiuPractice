package main

import "fmt"

type SortType int

const (
	Ascending SortType = iota
	Descending
)

func bubbleSort(arr []int, sortType SortType) {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		swapped := false
		for j := 0; j < n-i-1; j++ {
			shouldSwap := (sortType == Ascending && arr[j] > arr[j+1]) || (sortType == Descending && arr[j] < arr[j+1])
			if shouldSwap {
				arr[j], arr[j+1] = arr[j+1], arr[j]
				swapped = true
			}
		}
		if !swapped {
			break
		}
	}
}

func useme() {
	arr := []int{64, 25, 12, 22, 11}
	sortType := Ascending // Change to Descending for descending
	bubbleSort(arr, sortType)
	fmt.Println("Sorted array:", arr)
}
