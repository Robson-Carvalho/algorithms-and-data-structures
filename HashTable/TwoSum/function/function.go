package function

func TwoSum(nums []int, target int)  []int {
	hash := make(map[int]int)
	
	for i, num := range nums {
		complement := target - num

		if index, exists  := hash[complement]; exists{
			return []int{i, index}
		}
		hash[num] = i
	}


	return []int{}
}