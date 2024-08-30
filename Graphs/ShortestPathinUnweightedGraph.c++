#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
using namespace std;
void CreateGraph(int u, int v, unordered_map<int, list<int> > &Adj)
{
    Adj[u].push_back(v);
    Adj[v].push_back(u);
}
int main()
{
    int n;
    cout << "Enter number of vertices : ";
    cin >> n;

    int m;
    cout << "Enter number of edges : ";
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

    int source;
    cout << "Enter Source City : ";
    cin >> source;

    int dest;
    cout << "Enter Destination City : ";
    cin >> dest;

    // BFS
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;

    q.push(source);
    visited[source] = 1;
    parent[source] = -1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : Adj[front])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }

    // Checking Answer
    vector<int> ans;
    ans.push_back(dest);
    int currCity = dest;
    while (currCity != source)
    {
        currCity = parent[currCity];
        ans.push_back(currCity);
    }

    reverse(ans.begin(), ans.end());

    for (auto i : ans)
    {
        cout << i << " -> ";
    }
    cout << endl;

    return 0;
}