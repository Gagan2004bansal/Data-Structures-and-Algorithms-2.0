package files

import "fmt"

func KadaneAlgo() {
	fmt.Println("Kadane Algorithm")

	arr := []int{2, 3, -8, 7, -1, 2, 3}

	maxSum := 0
	currSum := 0

	for i := range arr {
		currSum += arr[i]
		maxSum = max(maxSum, currSum)

		if currSum < 0 {
			currSum = 0
		}
	}

	fmt.Println(maxSum)
}
