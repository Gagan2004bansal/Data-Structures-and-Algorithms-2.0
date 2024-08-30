#include <iostream>
#include <list>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;
// Directed Graph
void CreateGraph(int u, int v, unordered_map<int, list<int> > &Adj)
{
    Adj[u].push_back(v);
}
void TopoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int> > &Adj)
{
    visited[node] = true;

    for (auto neighbour : Adj[node])
    {
        if (!visited[neighbour])
        {
            TopoSort(neighbour, visited, s, Adj);
        }
    }

    s.push(node);
}
int main()
{
    int n;
    cout << "Enter number of vertices : ";
    cin >> n;

    int m;
    cout << "Enter number of egdes : ";
    cin >> m;

    unordered_map<int, list<int> > Adj;
    for (int i = 0; i < m; i++)
    {
        int u;
        cin >> u;

        int v;
        cin >> v;

        CreateGraph(u, v, Adj);
    }

    vector<bool> visited(n);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            TopoSort(i, visited, s, Adj);
        }
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
    return 0;
}