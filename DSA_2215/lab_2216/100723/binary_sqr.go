/*
!Problem: Find the square root of a number using binary search
Input a number: 88

* Note: a square root of a number is the number between 0 and the number that when multiplied by itself gives the number.
* Lower bound = 0
* Upper bound = number
? Guess = (lower + upper) / 2

threshold: something

Result =  guess * guess - number    // if result is less than threshold, then guess is the square root of the number
*/

package main

import (
	"fmt"
	"math"
	"time"
)

func squareRootBinarySearch(x float64, tolerance float64, maxIterations int) float64 {
	if x < 0 {
		panic("Cannot find square root of a negative number")
	}

	low := 0.0
	high := x

	guess := (low + high) / 2.0

	for i := 0; i < maxIterations; i++ {

		guessSquared := guess * guess

		if math.Abs(guessSquared-x) < tolerance {
			return guess
		}

		if guessSquared > x {
			high = guess
		} else {
			low = guess
		}

		guess = (low + high) / 2.0
	}

	return guess
}

func main() {
	var x float64
	fmt.Print("Input a number: ")
	fmt.Scan(&x)

	tolerance := 1e-5
	maxIterations := 100

	startTime := time.Now()
	result := squareRootBinarySearch(x, tolerance, maxIterations)
	endTime := time.Now()

	fmt.Printf("The square root of %.2f is approximately %.5f\n", x, result)
	fmt.Println("Time taken:", endTime.Sub(startTime))
}
