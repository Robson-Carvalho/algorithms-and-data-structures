package main

import (
	"fmt"

	"github.com/robson-carvalho/algorithms-and-data-structures/HashTable/TwoSum/function"
)

func main() {
	nums1 := []int{2,7,11,15}
	target1 := 9

	nums2 := []int{3,2,4}
	target2 := 6

	nums3 := []int{3,3}
	target3 := 6

	fmt.Println(function.TwoSum(nums1, target1))
	fmt.Println(function.TwoSum(nums2, target2))
	fmt.Println(function.TwoSum(nums3, target3))
}