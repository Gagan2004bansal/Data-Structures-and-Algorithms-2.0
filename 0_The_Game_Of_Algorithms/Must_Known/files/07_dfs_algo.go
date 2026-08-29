package files

import "fmt"

func dfs(node int, vis []bool, adj map[int][]int) {
	fmt.Println(node, " -> ")

	for _, nbr := range adj[node] {
		if !vis[nbr] {
			vis[nbr] = true
			dfs(nbr, vis, adj)
		}
	}
}

func DFSAlgo() {

	fmt.Println("DFS Algorithm")

	adj := make(map[int][]int)

	adj[0] = []int{1, 2}
	adj[1] = []int{0, 2}
	adj[2] = []int{0, 1, 3, 4}
	adj[3] = []int{2}
	adj[4] = []int{2}

	vis := make([]bool, 5)

	for i := range vis {
		if !vis[i] {
			vis[i] = true
			dfs(i, vis, adj)
		}
	}
}
