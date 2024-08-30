#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;
void createGraph(int u, int v, unordered_map<int, list<int> > &Adj)
{
    Adj[u].push_back(v);
}
int main()
{
    int n;
    cout << "Enter the number of vertices : ";
    cin >> n;

    int m;
    cout << "Enter the number of edges : ";
    cin >> m;

    unordered_map<int, list<int> > Adj;
    for (int i = 0; i < m; i++)
    {
        int u;
        cin >> u;

        int v;
        cin >> v;

        createGraph(u, v, Adj);
    }

    // Indegree Found Step 1
    vector<int> Indegree(n);
    for (auto i : Adj)
    {
        for (auto j : i.second)
        {
            Indegree[j]++;
        }
    }

    // Queue Insertion Step 2
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (Indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // BFS
    vector<int> ans;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        ans.push_back(temp);

        for (auto neighbour : Adj[temp])
        {
            Indegree[neighbour]--;
            if (Indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    for (auto j : ans)
    {
        cout << j << " ";
    }

    cout << endl;

    return 0;
}