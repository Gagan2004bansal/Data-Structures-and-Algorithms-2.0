package files

import "fmt"

func partition(arr []int, start int, end int) int {
	pivot := arr[end]

	i := start - 1

	for j := start; j < end; j++ {
		if arr[j] <= pivot {
			i++
			arr[i], arr[j] = arr[j], arr[i]
		}
	}

	arr[i+1], arr[end] = arr[end], arr[i+1]

	return i + 1
}

func quick_sort(arr []int, start int, end int) {
	if start >= end {
		return
	}

	pivotIndex := partition(arr, start, end)

	quick_sort(arr, start, pivotIndex-1)
	quick_sort(arr, pivotIndex+1, end)
}

func QuickSort() {
	fmt.Println("Quick Sort")

	vector := []int{3, 2, 5, 1, 4}

	// vector -> 3, 2, 5, 1, 4
	// O/P    -> 1, 2, 3, 4, 5

	quick_sort(vector, 0, len(vector)-1)

	fmt.Println(vector)
}
