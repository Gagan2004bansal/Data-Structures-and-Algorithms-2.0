package files

import "fmt"

func BinarySearch() {

	fmt.Println("Binary Search")

	var arr []int

	arr = append(arr, 1)
	arr = append(arr, 2)
	arr = append(arr, 3)
	arr = append(arr, 4)
	arr = append(arr, 4)
	arr = append(arr, 5)
	// arr -> 1, 2, 3, 4, 4, 5

	var target int = 2

	var s, e, mid int = 0, len(arr) - 1, 0

	found := false

	for s <= e {
		mid = s + (e-s)/2
		if arr[mid] == target {
			fmt.Println("target is found at", mid)
			found = true
			break
		} else if arr[mid] > target {
			e = mid - 1
		} else {
			s = mid + 1
		}
	}

	if !found {
		fmt.Println("Target is not present in array/slice/vector")
	}
}
