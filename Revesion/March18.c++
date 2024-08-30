// // Cycle Detection in Directed Graph using BFS
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <unordered_map>
// using namespace std;
// void CreateGraph(int u, int v, unordered_map<int, vector<int> > &Adj)
// {
//     Adj[u].push_back(v);
// }
// int main()
// {
//     int n;
//     cout << "Enter Number of Vertices : ";
//     cin >> n;

//     int m;
//     cout << "Enter Number of Edges : ";
//     cin >> m;

//     unordered_map<int, vector<int> > Adj;
//     for (int i = 0; i < m; i++)
//     {
//         int u;
//         cin >> u;

//         int v;
//         cin >> v;

//         CreateGraph(u, v, Adj);
//     }

//     vector<int> Indegree(n);
//     for (auto i : Adj)
//     {
//         for (auto j : i.second)
//         {
//             Indegree[j]++;
//         }
//     }

//     queue<int> q;
//     for (int i = 0; i < n; i++)
//     {
//         if (Indegree[i] == 0)
//         {
//             q.push(i);
//         }
//     }

//     int count = 0;
//     while (!q.empty())
//     {
//         int temp = q.front();
//         q.pop();

//         count++;

//         for (auto neighbour : Adj[temp])
//         {
//             Indegree[neighbour]--;
//             if (Indegree[neighbour] == 0)
//             {
//                 q.push(neighbour);
//             }
//         }
//     }

//     if (count == n)
//     {
//         cout << "False" << endl;
//     }
//     else
//     {
//         cout << "True" << endl;
//     }
//     return 0;
// }

// Cycle Detection in Directed Graph using DFS
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;
// void CreateGraph(int u, int v, unordered_map<int, vector<int> > &adj)
// {
//     adj[u].push_back(v);
// }
// bool CycleDetect(int node, unordered_map<int, vector<int> > &adj, vector<bool> &visited, vector<bool> &dfsVisited)
// {
//     visited[node] = true;
//     dfsVisited[node] = true;

//     for (auto neighbour : adj[node])
//     {
//         if (!visited[neighbour])
//         {
//             bool ans = CycleDetect(neighbour, adj, visited, dfsVisited);
//             if (ans)
//             {
//                 return true;
//             }
//         }
//         else if (dfsVisited[neighbour])
//         {
//             return true;
//         }
//     }

//     dfsVisited[node] = false;
//     return false;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int m;
//     cin >> m;

//     unordered_map<int, vector<int> > adj;

//     for (int i = 0; i < m; i++)
//     {
//         int u;
//         cin >> u;

//         int v;
//         cin >> v;

//         CreateGraph(u, v, adj);
//     }

//     vector<bool> visited(n, false);
//     vector<bool> dfsVisited(n, false);
//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             bool ans = CycleDetect(i, adj, visited, dfsVisited);
//             if (ans == true)
//             {
//                 cout << "Cycle Detected !" << endl;
//                 exit(0);
//             }
//         }
//     }

//     cout << "Cycle Not Detected !" << endl;
//     return 0;
// }

// Topological Sort using DFS
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
void CreateGraph(int u, int v, unordered_map<int, vector<int> > &adj)
{
    adj[u].push_back(v);
}
void dfs(int node, vector<bool> &visited, stack<int> &st, unordered_map<int, vector<int> > &adj)
{
    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, visited, st, adj);
        }
    }

    st.push(node);
}

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    unordered_map<int, vector<int> > adj;
    for (int i = 00; i < m; i++)
    {
        int u;
        cin >> u;

        int v;
        cin >> v;

        CreateGraph(u, v, adj);
    }

    vector<int> Indegree(n);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            Indegree[j]++;
        }
    }

    vector<int> ans;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (Indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        ans.push_back(temp);

        for (auto neighbour : adj[temp])
        {
            Indegree[neighbour]--;
            if (Indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}