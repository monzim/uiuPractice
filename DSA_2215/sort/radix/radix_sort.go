package main

import (
	"fmt"
)

func countingSort(arr []int, exp int) {
	n := len(arr)
	output := make([]int, n)
	count := make([]int, 10)

	for i := 0; i < n; i++ {
		count[(arr[i]/exp)%10]++
	}

	for i := 1; i < 10; i++ {
		count[i] += count[i-1]
	}

	for i := n - 1; i >= 0; i-- {
		output[count[(arr[i]/exp)%10]-1] = arr[i]
		count[(arr[i]/exp)%10]--
	}

	for i := 0; i < n; i++ {
		arr[i] = output[i]
	}
}

func radixSort(arr []int) {
	maxVal := arr[0]
	for _, val := range arr {
		if val > maxVal {
			maxVal = val
		}
	}

	for exp := 1; maxVal/exp > 0; exp *= 10 {
		countingSort(arr, exp)
	}
}

func useMe() {
	arr := []int{170, 45, 75, 90, 802, 24, 2, 66}
	radixSort(arr)
	fmt.Println("Sorted array:", arr)
}
