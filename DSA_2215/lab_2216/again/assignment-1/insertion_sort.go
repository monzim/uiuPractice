package main

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
