package main

import (
	"container/list"
	"fmt"
)

type Queue struct {
	list *list.List
}

func NewQueue() *Queue {
	return &Queue{list: list.New()}
}

func (q *Queue) Add(item int) {
	q.list.PushBack(item)
}

func (q *Queue) Remove() int {
	element := q.list.Front()
	if element == nil {
		return -1
	}
	q.list.Remove(element)
	return element.Value.(int)
}

func (q *Queue) Show() {
	for e := q.list.Front(); e != nil; e = e.Next() {
		fmt.Printf("%d ", e.Value)
	}
	fmt.Println()
}

func (q *Queue) Middle() int {
	if q.list.Len() == 0 {
		return -1
	}
	fast := q.list.Front()
	slow := q.list.Front()
	for fast != nil && fast.Next() != nil {
		fast = fast.Next().Next()
		slow = slow.Next()
	}
	return slow.Value.(int)
}

func (q *Queue) Search(item int) bool {
	for e := q.list.Front(); e != nil; e = e.Next() {
		if e.Value == item {
			return true
		}
	}
	return false
}

func useMe() {
	queue := NewQueue()
	queue.Add(1)
	queue.Add(2)
	queue.Add(3)
	queue.Show()

	fmt.Printf("Middle element: %d\n", queue.Middle())

	fmt.Printf("Searching for 2: %t\n", queue.Search(2))

	item := queue.Remove()
	if item != -1 {
		fmt.Printf("Removed item: %d\n", item)
	}

	queue.Show()
}

func main() {
	useMe()
}
