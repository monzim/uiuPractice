package main

import "fmt"

func main() {
	var i, j, n int

	print("Enter the number of rows: ")
	fmt.Scan(&n)

	for i = 1; i <= n; i++ {
		for j = 1; j <= n-i; j++ {
			fmt.Print(" ")
		}
		for j = 1; j <= 2*i-1; j++ {
			fmt.Print("*")
		}
		fmt.Println()
	}

}
