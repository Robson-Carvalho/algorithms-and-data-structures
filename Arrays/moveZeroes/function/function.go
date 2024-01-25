package function

import "fmt"

func MoveZeroes(nums []int){
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