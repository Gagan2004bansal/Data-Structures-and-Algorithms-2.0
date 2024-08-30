#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;
class graph
{
public:
    unordered_map<int, list<pair<int, int> > > Adj;

    void CreateGraph(int u, int v, int w)
    {
        Adj[u].push_back(make_pair(v, w));
    }

    void Display()
    {
        for (auto i : Adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "[" << j.first << "," << j.second << "] ,";
            }

            cout << endl;
        }
    }

    void TopoSort(int node, unordered_map<int, bool> &visited, stack<int> &s)
    {
        visited[node] = true;

        for (auto neighbour : Adj[node])
        {
            if (!visited[neighbour.first])
            {
                TopoSort(neighbour.first, visited, s);
            }
        }

        s.push(node);
    }

    void getShortestPath(int src, stack<int> &s, vector<int> &distance)
    {
        distance[src] = 0;

        while (!s.empty())
        {
            int temp = s.top();
            s.pop();

            if (distance[temp] != INT_MAX)
            {
                for (auto neighbour : Adj[temp])
                {
                    if (distance[temp] + neighbour.second < distance[neighbour.first])
                    {
                        distance[neighbour.first] = distance[temp] + neighbour.second;
                    }
                }
            }
        }
    }
};
int main()
{
    int n;
    cout << "Enter number of vertices : ";
    cin >> n;

    int m;
    cout << "Enter number of edges : ";
    cin >> m;

    graph g;

    for (int i = 0; i < m; i++)
    {
        int u;
        cin >> u;

        int v;
        cin >> v;

        int w; // Weight
        cin >> w;

        g.CreateGraph(u, v, w);
    }

    g.Display();

    stack<int> s;
    unordered_map<int, bool> visited;

    // Topological Sort
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.TopoSort(i, visited, s);
        }
    }

    int src = 0;
    vector<int> distance(n);
    for (int i = 0; i < n; i++)
    {
        distance[i] = INT_MAX;
    }

    g.getShortestPath(src, s, distance);

    for (int i = 0; i < n; i++)
    {
        cout << distance[i] << " ";
    }
    cout << endl;
    return 0;
}