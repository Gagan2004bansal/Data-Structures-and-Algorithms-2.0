package files

import "fmt"

func kahn_algo(adj map[int][]int) {

	size := len(adj)
	vis := make([]int, size)

	queue := []int{}

	for i := range size {
		for _, nbr := range adj[i] {
			vis[nbr]++
		}
	}

	for i := range vis {
		if vis[i] == 0 {
			queue = append(queue, i)
		}
	}

	for len(queue) > 0 {
		node := queue[0]
		queue = queue[1:]

		fmt.Print(node, " -> ")

		for _, nbr := range adj[node] {
			vis[nbr]--
			if vis[nbr] == 0 {
				queue = append(queue, nbr)
			}
		}
	}
}

func KahnAlgo() {
	fmt.Println("Kahn Algorithm - Topological Sort")

	adj := make(map[int][]int)

	adj[0] = []int{1, 2}
	adj[1] = []int{2}
	adj[2] = []int{3, 4}
	adj[3] = []int{}
	adj[4] = []int{}

	kahn_algo(adj)
}
