// DFS TRAVERSAL

// #include <iostream>
// #include <unordered_map>
// #include <list>
// #include <vector>
// using namespace std;
// void CreateGraph(int u, int v, vector<vector<int> > &Adj)
// {
//     Adj[u].push_back(v);
// }
// bool CycleDetect(int node, vector<bool> &visited, vector<bool> &dfsVisited, vector<vector<int> > &Adj)
// {
//     visited[node] = true;
//     dfsVisited[node] = true;

//     for (auto neighbour : Adj[node])
//     {
//         if (!visited[neighbour])
//         {
//             bool ans = CycleDetect(neighbour, visited, dfsVisited, Adj);
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
//     cout << "Enter the number of vertices : ";
//     cin >> n;

//     int m;
//     cout << "Enter the number of edges : ";
//     cin >> m;

//     vector<vector<int> > Adj(n);
//     for (int i = 0; i < m; i++)
//     {
//         int u;
//         cin >> u;

//         int v;
//         cin >> v;

//         CreateGraph(u, v, Adj);
//     }

//     vector<bool> visited(n, false);
//     vector<bool> dfsVisited(n, false);

//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             bool ans = CycleDetect(i, visited, dfsVisited, Adj);
//             if (ans)
//             {
//                 cout << "Cycle Detected !" << endl;
//                 exit(0);
//             }
//         }
//     }

//     cout << "No Cycle Detected !" << endl;
//     return 0;
// }

// BFS TRAVERSAL

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
using namespace std;
void CreateGraph(int u, int v, unordered_map<int, list<int> > &Adj)
{
    Adj[u].push_back(v);
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

    vector<int> Indegree(n);
    for (auto i : Adj)
    {
        for (auto j : i.second)
        {
            Indegree[j]++;
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

    int count = 0;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        count++;

        for (auto neighbour : Adj[temp])
        {
            Indegree[neighbour]--;
            if (Indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    if (count == n)
    {
        cout << "False" << endl;
    }
    else
    {
        cout << "True" << endl;
    }
    return 0;
}