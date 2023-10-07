/*
	How to run: make sure you have installed go in your machine
	run: go run main.go

	If you do'nt have go on your machine you can run the build binnary.
	Windows: main.exe
	Linux/mac: main

	Example Input File: hello.txt
	Example input file must follow this syntax
	1 2 77 88 0 11
	5 10 20 25 30
	42 17 9 6 3

*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"time"
)

func main() {

	// test input file: input.txt
	integers, err := getInputFileFromFilename()
	if err != nil {
		fmt.Println(err)
		os.Exit(1)
	}

	fmt.Println("List of integers:", integers)

	// prompt user for sorting algorithm
	algorithm := askForAlgorithm()
	order := askForOrderType()

	fmt.Println("Input data:")

	fmt.Println("Choose algorithm: %s", algorithm)
	fmt.Println("Choose order: %s", order)

	var timeTaken time.Duration

	switch algorithm {
	case BUBBLE:
		timeTaken = withTiming(func() {
			bubbleSort(integers, order)
		})
	case INSERTION:
		timeTaken = withTiming(func() {
			insertionSort(integers, order)

		})
	case SELECTION:
		timeTaken = withTiming(func() {
			selectionSort(integers, order)
		})
	default:
		timeTaken = withTiming(func() {
			bubbleSort(integers, order)
		})
	}

	fmt.Println("Sorted data:", integers)

	// ask user if they want to save the sorted data to a file
	fmt.Println("Do you want to save the sorted data to a file? (y/n)")

	var input string
	fmt.Scanln(&input)

	if input == "y" {
		saveToFile(integers, timeTaken)
	}

	fmt.Println("Thank you for using the program!")

}

// create a enum for sorting order

type SortAlgorithm int

const (
	BUBBLE SortAlgorithm = iota
	INSERTION
	SELECTION
)

func askForAlgorithm() SortAlgorithm {

	fmt.Println("Please choose a sorting algorithm:  (default: 1)")
	fmt.Println("1. Bubble Sort")
	fmt.Println("2. Insertion Sort")
	fmt.Println("3. Selection Sort")

	var input int
	fmt.Scanln(&input)

	switch input {
	case 1:
		return BUBBLE
	case 2:
		return INSERTION
	case 3:
		return SELECTION
	default:
		return BUBBLE
	}

}

func askForOrderType() SortOrder {

	fmt.Println("Please choose a sorting order: (default: 1)")
	fmt.Println("1. Ascending")
	fmt.Println("2. Descending")

	var input int
	fmt.Scanln(&input)

	switch input {
	case 1:
		return ASC
	case 2:
		return DESC
	default:
		return ASC
	}

}

func getInputFileFromFilename() ([]int, error) {

	fmt.Println("Please enter the input file name:")

	var input string
	fmt.Scanln(&input)

	bytesData, err := os.ReadFile(input)
	if err != nil {
		return nil, err
	}

	integers := []int{}

	scanner := bufio.NewScanner(strings.NewReader(string(bytesData)))
	for scanner.Scan() {
		line := scanner.Text()
		// Split the line by spaces to get individual numbers
		numStrings := strings.Fields(line)
		for _, numStr := range numStrings {
			num, err := strconv.Atoi(numStr)
			if err != nil {
				return nil, err
			}
			integers = append(integers, num)
		}
	}

	if err := scanner.Err(); err != nil {
		return nil, err
	}

	return integers, nil

}

type SortOrder int

const (
	ASC SortOrder = iota
	DESC
)

func bubbleSort(arr []int, order SortOrder) {
	n := len(arr)
	swapped := true

	for swapped {
		swapped = false
		for i := 1; i < n; i++ {
			// Check the sorting order and swap accordingly
			if (order == ASC && arr[i-1] > arr[i]) || (order == DESC && arr[i-1] < arr[i]) {
				// Swap elements arr[i-1] and arr[i]
				arr[i-1], arr[i] = arr[i], arr[i-1]
				swapped = true
			}
		}
		n-- // Reduce the number of elements to check on each iteration
	}
}

func insertionSort(arr []int, order SortOrder) {
	for i := 1; i < len(arr); i++ {
		key := arr[i]
		j := i - 1

		// Move elements of arr[0..i-1] that are greater than key
		// to one position ahead of their current position

		for j >= 0 && ((order == ASC && arr[j] > key) || (order == DESC && arr[j] < key)) {
			arr[j+1] = arr[j]
			j--
		}
		arr[j+1] = key
	}
}

func selectionSort(arr []int, order SortOrder) {
	n := len(arr)

	for i := 0; i < n-1; i++ {
		// Find the minimum or maximum element's index based on the sorting order
		minMaxIndex := i
		for j := i + 1; j < n; j++ {
			if (order == ASC && arr[j] < arr[minMaxIndex]) || (order == DESC && arr[j] > arr[minMaxIndex]) {
				minMaxIndex = j
			}
		}

		// Swap the found minimum or maximum element with arr[i]
		arr[i], arr[minMaxIndex] = arr[minMaxIndex], arr[i]
	}
}

func withTiming(fn func()) time.Duration {
	start := time.Now()
	fn()
	end := time.Now()
	timeTaken := end.Sub(start)
	fmt.Println("Time taken:", timeTaken)

	return timeTaken
}

// save sorted data to a file
func saveToFile(integers []int, timeTaken time.Duration) {
	fmt.Println("Please enter the output file name:")

	var input string
	fmt.Scanln(&input)

	f, err := os.Create(input)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer f.Close()

	for _, i := range integers {
		_, err := f.WriteString(strconv.Itoa(i) + " ")
		if err != nil {
			fmt.Println(err)
			f.Close()
			return
		}
	}

	// _, err = f.WriteString("\nTime taken: " + timeTaken.String() + "\nLength of the array: " + strconv.Itoa(len(integers)))
	// if err != nil {
	// 	fmt.Println(err)
	// 	f.Close()
	// 	return
	// }

	err = f.Close()
	if err != nil {
		fmt.Println(err)
		return
	}

	fmt.Println("Sorted data saved to file:", input)

}
