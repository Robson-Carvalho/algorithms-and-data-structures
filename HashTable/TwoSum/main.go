package main

import "fmt"

func twoSum(nums []int, target int) []int {
	hash := make(map[int]int)

	for i, num := range nums {
		complement := target - num

		if index, exists := hash[complement]; exists {
			return []int{i, index}
		}
		hash[num] = i
	}

	return []int{}
}

func main() {
	nums1 := []int{2, 7, 11, 15}
	target1 := 9

	nums2 := []int{3, 2, 4}
	target2 := 6

	nums3 := []int{3, 3}
	target3 := 6

	fmt.Println(twoSum(nums1, target1))
	fmt.Println(twoSum(nums2, target2))
	fmt.Println(twoSum(nums3, target3))
}