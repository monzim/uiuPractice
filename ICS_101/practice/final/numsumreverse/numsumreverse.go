package main

import (
	"fmt"
	"math"
)

func sum_digits(n int) int {
	if n == 0 {
		return 0
	}
	return (n % 10) + sum_digits(n/10)
}
func reverse(n int) int {
	if n == 0 {
		return 0
	}
	return (n%10)*int(math.Round(math.Pow(10, digits(n)))) + reverse(n/10)
}

func digits(n int) float64 {
	if n == 0 {
		return 1
	}
	return 1 + digits(n/10)
}

func main() {
	var n int
	fmt.Print("Enter a number: ")
	fmt.Scan(&n)

	fmt.Println("Sum of digits of", n, "is", sum_digits(n))
	fmt.Println("Reverse of", n, "is", reverse(n))

}
