package main

import (
	"fmt"

	"github.com/robson-carvalho/algorithms-and-data-structures/Arrays/firstUniqChar/function"
)

func main() {
	fmt.Println(function.FirstUniqChar("leetcode"))
	fmt.Println(function.FirstUniqChar("loveleetcode"))
	fmt.Println(function.FirstUniqChar("aabb"))
	fmt.Println(function.FirstUniqChar("z"))
}