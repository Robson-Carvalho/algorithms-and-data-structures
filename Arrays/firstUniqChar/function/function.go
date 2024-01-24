package function

func FirstUniqChar(s string) int {
	arr := [26]int{}

	for _, value := range s {
		arr[value-97]++
	}

	for i, value := range s {
		if arr[value-97] == 1  {
			return i
		}
	}

	return -1
}
