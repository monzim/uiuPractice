package main

func bnSearchAndIntertPosition(arr []int, target, low, high int) int {
	if low > high {
		return low
	}

	mid := low + (high-low)/2
	if arr[mid] == target {
		return mid
	} else if arr[mid] < target {
		return bnSearchAndIntertPosition(arr, target, mid+1, high)
	} else {
		return bnSearchAndIntertPosition(arr, target, low, mid-1)
	}
}

func selectionSort(arr []int) {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		minIdx := i
		for j := i + 1; j < n; j++ {
			if arr[j] < arr[minIdx] {
				minIdx = j
			}
		}
		arr[i], arr[minIdx] = arr[minIdx], arr[i]
	}
}

func insertionSort(arr []int) {
	n := len(arr)
	for i := 1; i < n; i++ {
		key := arr[i]
		j := i - 1

		for j >= 0 && arr[j] > key {
			arr[j+1] = arr[j]
			j = j - 1
		}

		arr[j+1] = key
	}
}

func searchInsert(arr []int, target int) int {
	return bnSearchAndIntertPosition(arr, target, 0, len(arr)-1)
}
