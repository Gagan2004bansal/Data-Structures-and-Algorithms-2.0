#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
void CreateAdjList(int u, int v, unordered_map<int, vector<int> > &Adj)
{
    // Directed Graph
    Adj[u].push_back(v);
}
void BFS(vector<int> &ans, unordered_map<int, vector<int> > &Adj, unordered_map<int, bool> &visited, int node)
{

    visited[node] = true;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        ans.push_back(temp);

        for (auto neighbour : Adj[node])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}
bool cycleDetect(int node, unordered_map<int, bool> &marking, unordered_map<int, vector<int> > &Adj)
{
    queue<int> q;
    unordered_map<int, int> parent;
    marking[node] = true;
    parent[node] = -1;
    q.push(node);

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        for (auto neighbour : Adj[temp])
        {
            if (marking[neighbour] == true && neighbour != parent[temp])
            {
                return true;
            }
            else if (!marking[neighbour])
            {
                q.push(neighbour);
                marking[neighbour] = true;
                parent[neighbour] = temp;
            }
        }
    }

    return false;
}
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    // Graph Can Be Directed Or Undirected

    // Here we are making direct adjacent list
    unordered_map<int, vector<int> > Adj;
    for (int i = 0; i < m; i++)
    {
        int u;
        cin >> u;

        int v;
        cin >> v;

        CreateAdjList(u, v, Adj);
    }

    vector<int> ans;
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFS(ans, Adj, visited, i);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // Now we detect cycle in Undirected Graph using BFS Algo
    unordered_map<int, bool> marking;
    bool ans1 = false;
    for (int i = 0; i < n; i++)
    {
        if (!marking[i])
        {
            ans1 = cycleDetect(i, marking, Adj);
            if (ans1 == true)
            {
                cout << "Cycle Detect !" << endl;
                exit(0);
            }
        }
    }

    cout << "No Cycle Present" << endl;
    return 0;
}

// Now we are making UnDirected Graph
// and make Adj list using vector
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;
// void DFS(int node, vector<int> &ans, unordered_map<int, bool> &visited, unordered_map<int, vector<int> > &Adj)
// {
//     ans.push_back(node);
//     visited[node] = true;

//     for (auto neighbour : Adj[node])
//     {
//         if (!visited[neighbour])
//         {
//             DFS(neighbour, ans, visited, Adj);
//         }
//     }
// }
// bool CycleDetect(int node, int parent, unordered_map<int, bool> &marking, unordered_map<int, vector<int> > &Adj)
// {
//     marking[node] = true;

//     for (auto neighbour : Adj[node])
//     {
//         if (!marking[neighbour])
//         {
//             bool ans = CycleDetect(neighbour, node, marking, Adj);
//             if (ans)
//             {
//                 return true;
//             }
//         }
//         else if (neighbour != parent)
//         {
//             return true;
//         }
//     }

//     return false;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int m;
//     cin >> m;

//     vector<pair<int, int> > edges;
//     for (int i = 0; i < m; i++)
//     {
//         int u;
//         cin >> u;

//         int v;
//         cin >> v;

//         pair<int, int> edge = make_pair(u, v);
//         edges.push_back(edge);
//     }

//     // Now Creating Adj List
//     unordered_map<int, vector<int> > Adj;
//     for (int i = 0; i < edges.size(); i++)
//     {
//         int u = edges[i].first;
//         int v = edges[i].second;

//         Adj[u].push_back(v);
//         Adj[v].push_back(u);
//     }

//     // Transverse Using DFS
//     unordered_map<int, bool> visited;
//     vector<int> ans;

//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             DFS(i, ans, visited, Adj);
//         }
//     }

//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
//     cout << endl;

//     // Now we detect cycle in Undirected Graph using DFS Algo
//     unordered_map<int, bool> marking;
//     int parent = -1;
//     bool ans1 = false;
//     for (int i = 0; i < n; i++)
//     {
//         if (!marking[i])
//         {
//             ans1 = CycleDetect(i, parent, marking, Adj);
//             if (ans1 == true)
//             {
//                 cout << "Cycle Detect !" << endl;
//                 exit(0);
//             }
//         }
//     }

//     cout << "No Cycle Present" << endl;
//     return 0;
// }