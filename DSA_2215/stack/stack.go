package main

import "fmt"

type Stack []int

func (s *Stack) Push(item int) {
	*s = append(*s, item)
}

func (s *Stack) Pop() (int, bool) {
	if len(*s) == 0 {
		return 0, false
	}
	item := (*s)[len(*s)-1]
	*s = (*s)[:len(*s)-1]
	return item, true
}

func (s Stack) Find(item int) int {
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] == item {
			return i
		}
	}
	return -1
}

func (s *Stack) Remove(item int) {
	index := s.Find(item)
	if index != -1 {
		*s = append((*s)[:index], (*s)[index+1:]...)
	}
}

func (s Stack) Last() int {
	if len(s) == 0 {
		return -1
	}
	return s[len(s)-1]
}

func (s Stack) First() int {
	if len(s) == 0 {
		return -1
	}
	return s[0]
}

func (s Stack) Display() {
	for i := len(s) - 1; i >= 0; i-- {
		fmt.Printf("%d ", s[i])
	}
	fmt.Println()
}

func useMe() {
	stack := make(Stack, 0)
	stack.Push(1)
	stack.Push(2)
	stack.Push(3)
	stack.Display()

	item, ok := stack.Pop()
	if ok {
		fmt.Printf("Popped item: %d\n", item)
	}

	stack.Remove(2)
	fmt.Printf("Stack after removing 2: ")
	stack.Display()

	fmt.Printf("Index of 1: %d\n", stack.Find(1))
	fmt.Printf("Last item: %d\n", stack.Last())
	fmt.Printf("First item: %d\n", stack.First())
}

func main() {
	useMe()
}
