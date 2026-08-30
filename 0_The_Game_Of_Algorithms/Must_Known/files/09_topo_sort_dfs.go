package files

import "fmt"

func dfs_call(node int, vis []bool, adj map[int][]int, stack *[]int) {
	vis[node] = true

	for _, nbr := range adj[node] {
		if vis[nbr] == false {
			dfs_call(nbr, vis, adj, stack)
		}
	}

	*stack = append(*stack, node)
}

func topo_sort(adj map[int][]int) {

	size := len(adj)
	vis := make([]bool, size)

	var stack []int

	for i := range size {
		if vis[i] == false {
			dfs_call(i, vis, adj, &stack)
		}
	}

	for len(stack) > 0 {
		n := len(stack) - 1
		topNode := stack[n]
		stack = stack[:n]

		fmt.Print(topNode, " - ")
	}

}

func TopoSort() {

	fmt.Println("TopoSort - DFS Approach")

	adj := make(map[int][]int)

	adj[0] = []int{1, 2}
	adj[1] = []int{2}
	adj[2] = []int{3, 4}
	adj[3] = []int{}
	adj[4] = []int{}

	topo_sort(adj)
}
