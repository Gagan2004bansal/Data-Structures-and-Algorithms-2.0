#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void dfs(int node, int parent, int &timer, vector<int> &desc, vector<int> &low, unordered_map<int, bool> &vis,
         unordered_map<int, vector<int> > &adj, vector<vector<int> > &result)
{

    vis[node] = true;
    desc[node] = low[node] = timer++;

    for (auto nbr : adj[node])
    {
        // if parent and nbr is same
        if (parent == nbr)
        { // nbr -> neighbour node through adj list
            continue;
        }

        if (!vis[nbr])
        {
            dfs(nbr, node, timer, desc, low, vis, adj, result);

            low[node] = min(low[node], low[nbr]);

            if (low[nbr] > desc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);

                result.push_back(ans);
            }
        }
        else
        {
            low[node] = min(low[node], desc[nbr]);
        }
    }
}
int main()
{
    int n;
    cout << "Enter number of vertices : ";
    cin >> n;
    int m;
    cout << "Enter number of edges : ";
    cin >> m;

    unordered_map<int, vector<int> > adj;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> desc(n);
    vector<int> low(n);
    int parent = -1;
    int timer = 0;
    unordered_map<int, bool> vis;

    for (int i = 0; i < n; i++)
    {
        desc[i] = -1;
        low[i] = -1;
    }

    vector<vector<int> > result;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, timer, desc, low, vis, adj, result);
        }
    }

    for (auto it : result)
    {
        for (auto j : it)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}