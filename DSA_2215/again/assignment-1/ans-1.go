package main

import (
	"fmt"
)

func QuickSort(arr []int, low, high int) {
	if low < high {
		pivotIndex := Partition(arr, low, high)
		fmt.Printf("Pivot: %d, Array after partitioning: %v\n", arr[pivotIndex], arr)

		QuickSort(arr, low, pivotIndex-1)
		QuickSort(arr, pivotIndex+1, high)
	}
}

func Partition(arr []int, low, high int) int {

	pivot := arr[(low+high)/2]
	arr[(low+high)/2], arr[high] = arr[high], arr[(low+high)/2]
	i := low

	for j := low; j < high; j++ {
		if arr[j] > pivot {
			arr[i], arr[j] = arr[j], arr[i]
			i++
		}
	}

	arr[i], arr[high] = arr[high], arr[i]
	return i
}

func Do_A1() {
	arr := []int{20, 33, 41, 55, 56, 60, 61, 70}
	fmt.Println("Original Array:", arr)
	QuickSort(arr, 0, len(arr)-1)
	fmt.Println("Final Sorted Array in Descending Order:", arr)
}
