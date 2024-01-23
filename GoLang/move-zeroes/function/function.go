package function

import "fmt"

func MoveZeroes(nums []int){
	aux := []int{}

	for _, value := range nums {
		if value != 0 {
			aux = append(aux, value)
		}
	}

	zeroesCount := len(nums) - len(aux)
	for i := 0; i < zeroesCount; i++ {
		aux = append(aux, 0)
	}

	copy(nums, aux)

	fmt.Println(nums)
}