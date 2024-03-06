package main

import "fmt"

func factorial(num int) int {
	if num <= 1 {
		return num
	}

	return factorial(num-1) * num
}

func main() {
	fmt.Println(factorial(10))
}