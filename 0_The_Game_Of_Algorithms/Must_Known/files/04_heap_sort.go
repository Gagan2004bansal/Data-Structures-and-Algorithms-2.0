package files

import "fmt"

func swap(i, j int, arr []int) {
	temp := arr[i]
	arr[i] = arr[j]
	arr[j] = temp
}

func heapify(n, index int, arr []int) {
	root := index
	left := 2*index + 1
	right := 2*index + 2

	if left < n && arr[root] < arr[left] {
		root = left
	}

	if right < n && arr[root] < arr[right] {
		root = right
	}

	if root != index {
		swap(root, index, arr)
		heapify(n, root, arr)
	}
}

func heap_sort(arr []int) {

	fmt.Println("Heap Sort")

	len := len(arr)

	for i := (len / 2) - 1; i >= 0; i-- {
		heapify(len, i, arr)
	}

	for i := len - 1; i > 0; i-- {
		swap(0, i, arr)

		heapify(i, 0, arr)
	}

	fmt.Println(arr)
}

func HeapSort() {

	var arr []int

	arr = append(arr, 2)
	arr = append(arr, 3)
	arr = append(arr, 1)
	arr = append(arr, 5)
	arr = append(arr, 4)

	heap_sort(arr)
}
