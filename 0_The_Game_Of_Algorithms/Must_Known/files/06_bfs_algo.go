package files

import "fmt"

func bfs(node int, vis []bool, adj map[int][]int) {

	queue := []int{node}
	vis[node] = true

	for len(queue) > 0 {
		tempNode := queue[0]
		queue = queue[1:]

		fmt.Print(tempNode, " -> ")

		for _, nbr := range adj[node] {
			if !vis[nbr] {
				vis[nbr] = true
				queue = append(queue, nbr)
			}
		}
	}

}

func BFSAlgo() {

	fmt.Println("BFS Algorithm")

	adj := make(map[int][]int)

	adj[0] = []int{1, 2}
	adj[1] = []int{0, 2}
	adj[2] = []int{0, 1, 3, 4}
	adj[3] = []int{2}
	adj[4] = []int{2}

	vis := make([]bool, 5)

	for i := range vis {
		if !vis[i] {
			bfs(i, vis, adj)
		}
	}
}
