// Articulation point finding by Tarzan's Algortihtm
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}
void dfs(int node, int parent, int &timer, vector<int> &desc, vector<int> &low, unordered_map<int, bool> &vis, vector<int> &res, unordered_map<int, vector<int> > &adj)
{

    vis[node] = true;
    desc[node] = low[node] = timer++;
    int child = 0;

    for (auto nbr : adj[node])
    {
        if (parent == nbr)
        {
            continue;
        }

        if (!vis[nbr])
        {
            dfs(nbr, node, timer, desc, low, vis, res, adj);

            low[node] = min(low[node], low[nbr]);

            if (low[nbr] >= desc[node] && parent != -1)
            {
                res[node] = 1;
            }
            child++;
        }
        else
        {
            // Back Edge Case
            low[node] = min(low[node], desc[nbr]);
        }
    }

    if (parent == -1 && child > 1)
    {
        res[node] = 1;
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

    vector<int> res(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, timer, desc, low, vis, res, adj);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (res[i] != 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}

class Solution
{
public:
    void dfs(int i, int p, vector<int> &v, int v1[], int v2[], int &cnt, vector<int> adj[], vector<vector<int> > &ans)
    {
        v[i] = 1;
        v1[i] = cnt;
        v2[i] = cnt;
        cnt++;
        for (auto it : adj[i])
        {
            if (it == p)
            {
                continue;
            }
            if (v[it])
            {
                v1[i] = min(v1[i], v1[it]);
            }
            else
            {
                dfs(it, i, v, v1, v2, cnt, adj, ans);
                v1[i] = min(v1[i], v1[it]);
                if (v1[it] > v2[i])
                {
                    ans.push_back({i, it});
                }
            }
        }
    }
    vector<vector<int> > criticalConnections(int n, vector<vector<int> > &connections)
    {
        vector<int> adj[n];
        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int cnt = 1;
        vector<int> v(n, 0);
        int v1[n], v2[n];
        vector<vector<int> > ans;
        dfs(0, -1, v, v1, v2, cnt, adj, ans);
        return ans;
    }
};