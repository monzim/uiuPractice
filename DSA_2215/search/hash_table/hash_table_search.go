package main

import "fmt"

type HashTable struct {
	table map[int]int
}

func NewHashTable() *HashTable {
	return &HashTable{
		table: make(map[int]int),
	}
}

func (h *HashTable) Insert(key, value int) {
	h.table[key] = value
}

func (h *HashTable) Search(key int) int {
	if val, found := h.table[key]; found {
		return val
	}
	return -1
}

func useMe() {
	ht := NewHashTable()
	ht.Insert(1, 10)
	ht.Insert(2, 20)
	targetKey := 2
	value := ht.Search(targetKey)
	if value != -1 {
		fmt.Printf("Value for key %d is %d\n", targetKey, value)
	} else {
		fmt.Printf("Key %d not found in the hash table\n", targetKey)
	}
}

func main() {
	useMe()
}
