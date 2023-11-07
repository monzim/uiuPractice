/*
	Question 2 (10 Marks) - Linked List Operations
	Draw and provide code to perform within both singly and doubly linked lists:

		a) Insertion from both the beginning and end, as well as at any specified position
		b) Deletion from both the beginning and end, as well as at any specified position and
		c) Searching for any element .
		d) Searching for the middle element .
*/

package main

import "fmt"

type Node struct {
	data int
	next *Node
	prev *Node
}

type LinkedList struct {
	head     *Node
	isDoubly bool
	tail     *Node
}

func NewLinkedList(doubly bool) *LinkedList {
	return &LinkedList{
		head:     nil,
		isDoubly: doubly,
		tail:     nil,
	}
}

func (est *LinkedList) InsertAtBeginning(data int) {
	newNode := &Node{data, est.head, nil}

	if est.isDoubly {
		if est.head != nil {
			est.head.prev = newNode
		} else {
			est.tail = newNode
		}
	}

	est.head = newNode
}

func (est *LinkedList) InsertAtEnd(data int) {
	newNode := &Node{data, nil, nil}

	if est.head == nil {
		est.head = newNode
	} else {
		current := est.head
		for current.next != nil {
			current = current.next
		}
		current.next = newNode

		if est.isDoubly {
			newNode.prev = current
			est.tail = newNode
		}
	}
}

func (est *LinkedList) InsertAtPosition(data int, position int) {
	if position < 0 {
		fmt.Println("Invalid position")
		return
	}

	if position == 0 {
		est.InsertAtBeginning(data)
		return
	}

	newNode := &Node{data, nil, nil}
	current := est.head
	for i := 0; i < position-1; i++ {
		if current == nil {
			fmt.Println("Position exceeds the length of the list")
			return
		}
		current = current.next
	}
	if current == nil {
		fmt.Println("Position exceeds the length of the list")
		return
	}
	newNode.next = current.next
	current.next = newNode

	if est.isDoubly {
		newNode.prev = current
		if newNode.next != nil {
			newNode.next.prev = newNode
		} else {
			est.tail = newNode
		}
	}
}

func (est *LinkedList) DeleteFromBeginning() {
	if est.head == nil {
		return
	}
	if est.isDoubly && est.head.next != nil {
		est.head.next.prev = nil
	}
	est.head = est.head.next
}

func (est *LinkedList) DeleteFromEnd() {
	if est.head == nil {
		return
	}
	if est.head.next == nil {
		est.head = nil
		est.tail = nil
		return
	}
	current := est.head
	for current.next.next != nil {
		current = current.next
	}
	current.next = nil
	if est.isDoubly {
		est.tail = current
	}
}

func (est *LinkedList) DeleteAtPosition(p int) {
	if p < 0 || est.head == nil {
		return
	}

	if p == 0 {
		if est.isDoubly && est.head.next != nil {
			est.head.next.prev = nil
		}
		est.head = est.head.next
		return
	}

	current := est.head
	for i := 0; i < p-1; i++ {
		if current == nil || current.next == nil {
			return
		}
		current = current.next
	}
	if est.isDoubly && current.next != nil && current.next.next != nil {
		current.next.next.prev = current
	}
	current.next = current.next.next
}

func (est *LinkedList) SearchElement(data int) bool {
	c := est.head
	for c != nil {
		if c.data == data {
			return true
		}
		c = c.next
	}
	return false
}

func (est *LinkedList) FindMiddle() *Node {
	s := est.head
	f := est.head
	for f != nil && f.next != nil {
		s = s.next
		f = f.next.next
	}
	return s
}

func main() {
	singlyList := NewLinkedList(false)
	singlyList.InsertAtBeginning(1)
	singlyList.InsertAtEnd(3)
	singlyList.InsertAtPosition(2, 2)
	singlyList.InsertAtPosition(3, 3)

	fmt.Println("Singly Linked List:")
	current := singlyList.head
	for current != nil {
		fmt.Printf("%d -> ", current.data)
		current = current.next
	}
	fmt.Println()

	doublyList := NewLinkedList(true)
	doublyList.InsertAtBeginning(1)
	doublyList.InsertAtEnd(3)
	doublyList.InsertAtPosition(2, 1)
	doublyList.InsertAtPosition(3, 2)

	fmt.Println("Doubly Linked List:")
	current = doublyList.head
	for current != nil {
		fmt.Printf("%d -> ", current.data)
		current = current.next
	}
	fmt.Println()

	singlyList.DeleteFromBeginning()
	singlyList.DeleteFromEnd()
	singlyList.DeleteAtPosition(0)
	fmt.Printf("Singly List After Deletion: ")
	current = singlyList.head
	for current != nil {
		fmt.Printf("%d -> ", current.data)
		current = current.next
	}
	fmt.Println()

	doublyList.DeleteFromBeginning()
	doublyList.DeleteFromEnd()
	doublyList.DeleteAtPosition(1)
	fmt.Printf("Doubly List After Deletion: ")
	current = doublyList.head
	for current != nil {
		fmt.Printf("%d -> ", current.data)
		current = current.next
	}
	fmt.Println()

	searchElement := 2
	fmt.Printf("Search for element %d in Singly List: %v\n", searchElement, singlyList.SearchElement(searchElement))
	fmt.Printf("Search for element %d in Doubly List: %v\n", searchElement, doublyList.SearchElement(searchElement))

	singlyList.InsertAtEnd(4)
	singlyList.InsertAtEnd(5)
	middleSingly := singlyList.FindMiddle()
	fmt.Printf("Middle element in Singly List: %d\n", middleSingly.data)

	doublyList.InsertAtEnd(4)
	doublyList.InsertAtEnd(5)
	middleDoubly := doublyList.FindMiddle()
	fmt.Printf("Middle element in Doubly List: %d\n", middleDoubly.data)
}
