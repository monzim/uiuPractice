package main

import "fmt"

type SortType int

const (
	Ascending SortType = iota
	Descending
)

func insertionSort(arr []int, sortType SortType) {
	for i := 1; i < len(arr); i++ {
		key := arr[i]
		j := i - 1

		for j >= 0 && ((sortType == Ascending && arr[j] > key) || (sortType == Descending && arr[j] < key)) {
			arr[j+1] = arr[j]
			j--
		}

		arr[j+1] = key
	}
}

func useMe() {
	arr := []int{64, 25, 12, 22, 11}
	sortType := Ascending // Change to Descending for descending
	insertionSort(arr, sortType)
	fmt.Println("Sorted array:", arr)
}
