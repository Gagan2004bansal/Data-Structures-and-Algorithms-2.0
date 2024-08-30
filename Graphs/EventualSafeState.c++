// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;
// bool DFS(int node, vector<int> &path, vector<int> &vis, vector<int> &check, unordered_map<int, vector<int> > &adj)
// {
//     path[node] = 1;
//     vis[node] = 1;

//     for (auto nbr : adj[node])
//     {
//         if (!vis[nbr])
//         {
//             bool response = DFS(nbr, path, vis, check, adj);
//             if (response)
//             {
//                 check[node] = 0;
//                 return true;
//             }
//         }
//         else if (path[nbr])
//         {
//             check[node] = 0;
//             return true;
//         }
//     }

//     check[node] = 1;
//     path[node] = 0;
//     return false;
// }
// int main()
// {
//     int n;
//     cout << "Enter the number of nodes : ";
//     cin >> n;

//     int m;
//     cout << "Enter the number of edges : ";
//     cin >> m;

//     unordered_map<int, vector<int> > adj;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//     }

//     vector<int> vis(n, 0);
//     vector<int> path(n, 0);
//     vector<int> check(n, 0);
//     vector<int> safenode;

//     for (int i = 0; i < n; i++)
//     {
//         if (!vis[i])
//         {
//             bool ans = DFS(i, path, vis, check, adj);
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (check[i])
//         {
//             safenode.push_back(i);
//         }
//     }

//     cout << "Safe Node : ";
//     for (int i = 0; i < safenode.size(); i++)
//     {
//         cout << safenode[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    vector<vector<int> > graph;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int v;
            cin >> v;
            temp.push_back(v);
        }
        graph.push_back(temp);
    }

    // Reverse All edges
    vector<vector<int> > revAdj(n);
    vector<int> Indegree(n);
    for (int i = 0; i < n; i++)
    {
        // it -> i
        for (auto it : graph[i])
        {
            revAdj[it].push_back(i);
            Indegree[i]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (Indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> res;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        res.push_back(node);

        for (auto nbr : revAdj[node])
        {
            Indegree[nbr]--;
            if (Indegree[nbr] == 0)
            {
                q.push(nbr);
            }
        }
    }

    sort(res.begin(), res.end());

    cout << "Safe Node : ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}