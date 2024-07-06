package main

import "fmt"

func binarySearch(arr []int, target int, low int, high int) int {
	if low > high {
		return -1
	}

	mid := low + (high-low)/2
	if arr[mid] == target {
		return mid
	} else if arr[mid] < target {
		return binarySearch(arr, target, mid+1, high)
	} else {
		return binarySearch(arr, target, low, mid-1)
	}
}

func linearSearch(arr []int, target int) int {
	for i, v := range arr {
		if v == target {
			return i
		}
	}
	return -1
}

func test_linearSearch() {
	arr := []int{1, 2, 3, 4, 5}
	target := 5
	index := linearSearch(arr, target)
	if index != -1 {
		fmt.Printf("Target %d found at index %d\n", target, index)
	} else {
		fmt.Printf("Target %d not found in the array\n", target)
	}
}

func test_binarySearch() {
	arr := []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	target := 7
	result := binarySearch(arr, target, 0, len(arr)-1)
	if result != -1 {
		fmt.Printf("element found at index %d\n", result)
	} else {
		fmt.Println("element not found in the array")
	}
}
