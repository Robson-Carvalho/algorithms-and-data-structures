package main

import (
	"fmt"
)

func BinarySearch(arr []int, target int) *int {
	head := 0
	last := len(arr) - 1
	
	for head <= last{
		middle := (head + last) / 2

		if arr[middle] == target {
			return &middle
		}

		if arr[middle] > target {
			last = middle - 1
		}else {
			head = middle + 1
		}	
	}

	return nil
}

func main() {
	arr := []int{1,2,3,4,5,6,7,8,9,10}

	result := BinarySearch(arr, 1)

	if result != nil{
		fmt.Println(*result)
	}else{
		fmt.Println(nil)
	}
}