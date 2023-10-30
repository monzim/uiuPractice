package main

import "fmt"

func main() {
	stack := newStack()
	for {
		switch menu() {
		case 1:
			var value int
			fmt.Print("Enter value: ")
			fmt.Scanln(&value)
			stack.push(value)
		case 2:
			fmt.Println(stack.pop())
		case 3:
			fmt.Println(stack.size())
		case 4:
			fmt.Println(stack.top())
		case 5:
			fmt.Println(stack.data)
		case 6:
			return

		default:
			fmt.Println("Invalid choice")
		}
	}
}

func menu() int {
	fmt.Println("1. Push")
	fmt.Println("2. Pop")
	// stack size
	fmt.Println("3. Stack size")
	fmt.Println("4. top element")
	fmt.Println("5. Display stack")
	fmt.Println("6. Exit")
	fmt.Print("Enter your choice: ")

	var choice int
	fmt.Scanln(&choice)
	return choice
}

type stack struct {
	data []int
}

func newStack() *stack {
	return &stack{}
}

func (s *stack) push(value int) {
	s.data = append(s.data, value)
}

func (s *stack) pop() int {
	if len(s.data) == 0 {
		return -1
	}
	value := s.data[len(s.data)-1]
	s.data = s.data[:len(s.data)-1]
	return value
}

func (s *stack) size() int {
	return len(s.data)
}

func (s *stack) top() int {
	if len(s.data) == 0 {
		return -1
	}
	return s.data[len(s.data)-1]
}
