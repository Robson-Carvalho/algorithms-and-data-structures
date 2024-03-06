package main

import "fmt"

func moveZeroes(nums []int) {
	var lastZero int = 0

	for i := range nums {
		if nums[i] != 0 {
			aux := nums[lastZero]
			nums[lastZero] = nums[i]
			nums[i] = aux
			lastZero++
		}
	}

	fmt.Println(nums)
}

func main() {
	arr1 := []int{0, 1, 0, 3, 12}
	arr2 := []int{0}

	moveZeroes(arr1)
	moveZeroes(arr2)
}
