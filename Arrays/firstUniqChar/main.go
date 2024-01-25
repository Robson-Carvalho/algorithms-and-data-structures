package main

import "fmt"

func main() {
	fmt.Println(firstUniqChar("leetcode"))
	fmt.Println(firstUniqChar("loveleetcode"))
	fmt.Println(firstUniqChar("aabb"))
	fmt.Println(firstUniqChar("z"))
}

func firstUniqChar(s string) int {
	arr := [26]int{}

	for _, value := range s {
		arr[value-97]++
	}

	for i, value := range s {
		if arr[value-97] == 1 {
			return i
		}
	}

	return -1
}