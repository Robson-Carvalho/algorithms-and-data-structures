package main

import (
	"GoLang/function"
)

func main() {
	arr1 := []int{0,1,0,3,12}
	arr2 := []int{0}

	function.MoveZeroes(arr1)
	function.MoveZeroes(arr2)
}
