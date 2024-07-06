// implemented with golang language
package main

import (
	"fmt"
)

type Node struct {
	value int
	next  *Node
}

type LinkedList struct {
	head *Node
}

func (ll *LinkedList) InsertAtFront(value int) {
	newNode := &Node{value: value}
	newNode.next = ll.head
	ll.head = newNode
}

func (ll *LinkedList) InsertAtBack(value int) {
	newNode := &Node{value: value}
	if ll.head == nil {
		ll.head = newNode
		return
	}
	current := ll.head
	for current.next != nil {
		current = current.next
	}
	current.next = newNode
}

func (ll *LinkedList) InsertInMiddle(value, after int) {
	newNode := &Node{value: value}
	current := ll.head
	for current != nil && current.value != after {
		current = current.next
	}
	if current != nil {
		newNode.next = current.next
		current.next = newNode
	}
}

func (ll *LinkedList) DeleteAtFront() {
	if ll.head != nil {
		ll.head = ll.head.next
	}
}

func (ll *LinkedList) DeleteAtBack() {
	if ll.head == nil {
		return
	}
	if ll.head.next == nil {
		ll.head = nil
		return
	}
	current := ll.head
	for current.next.next != nil {
		current = current.next
	}
	current.next = nil
}

func (ll *LinkedList) Delete(value int) {
	if ll.head == nil {
		return
	}
	if ll.head.value == value {
		ll.head = ll.head.next
		return
	}
	current := ll.head
	for current.next != nil && current.next.value != value {
		current = current.next
	}
	if current.next != nil {
		current.next = current.next.next
	}
}

func (ll *LinkedList) PrintList() {
	current := ll.head
	for current != nil {
		fmt.Printf("%d ", current.value)
		current = current.next
	}

	fmt.Println()
}

func main() {
	ll := &LinkedList{}
	ll.PrintList()

	ll.InsertAtFront(1)
	ll.PrintList()

	ll.InsertAtBack(2)
	ll.PrintList()

	ll.InsertInMiddle(7, 1)
	ll.PrintList()

	ll.InsertAtFront(5)
	ll.PrintList()

	ll.InsertAtBack(3)
	ll.PrintList()

	ll.DeleteAtBack()
	ll.PrintList()

	ll.DeleteAtFront()
	ll.PrintList()

	ll.Delete(7)
	ll.PrintList()
}
