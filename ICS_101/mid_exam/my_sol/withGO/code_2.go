package main

import "fmt"

func main() {

	var notes []int = []int{100, 50, 20, 10, 5, 2, 1}
	var amount int

	fmt.Print("Enter the amount of money: ")
	fmt.Scanf("%d", &amount)

	for i := 0; i < len(notes); i++ {
		var num_notes int = amount / notes[i]
		fmt.Printf("%d notes of %d\n", num_notes, notes[i])
		amount = amount - num_notes*notes[i]

	}

}
