package files

import "fmt"

func merge_arr(arr []int, start, mid, end int) {
	var len1 int = mid - start + 1
	var len2 int = end - mid

	var arr1 = make([]int, len1)
	var arr2 = make([]int, len2)

	for i := 0; i < len1; i++ {
		arr1[i] = arr[start+i]
	}
	for i := 0; i < len2; i++ {
		arr2[i] = arr[mid+1+i]
	}

	var i, j int = 0, 0
	var k int = start

	for i < len1 && j < len2 {
		if arr1[i] <= arr2[j] {
			arr[k] = arr1[i]
			i++
		} else {
			arr[k] = arr2[j]
			j++
		}
		k++
	}

	for i < len1 {
		arr[k] = arr1[i]
		i++
		k++
	}

	for j < len2 {
		arr[k] = arr2[j]
		j++
		k++
	}
}

func merge_sort(vector []int, start int, end int) {
	if start >= end {
		return
	}

	mid := (start + end) / 2

	merge_sort(vector, start, mid)
	merge_sort(vector, mid+1, end)
	merge_arr(vector, start, mid, end)
}

func MergeSort() {

	fmt.Println("Merge Sort")

	var vector []int

	vector = append(vector, 3)
	vector = append(vector, 2)
	vector = append(vector, 5)
	vector = append(vector, 1)
	vector = append(vector, 4)
	// vector -> 3, 2, 5, 1, 4

	// O/P -> 1,2,3,4,5

	merge_sort(vector, 0, len(vector)-1)

	fmt.Println(vector)
}
