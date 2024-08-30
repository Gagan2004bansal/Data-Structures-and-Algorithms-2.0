// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <queue>
// #include <set>
// using namespace std;
// class graph
// {
// public:
//     unordered_map<int, set<int> > Adj; // Using Set can help us to give answer in Sorted Order

//     void CreateGraph(int u, int v)
//     {
//         Adj[u].insert(v);
//         Adj[v].insert(u);
//     }

//     void DFS(int node, vector<int> &ans, unordered_map<int, bool> &visited)
//     {

//         ans.push_back(node);
//         visited[node] = true;

//         for (auto i : Adj[node])
//         {
//             if (!visited[i])
//             {
//                 DFS(i, ans, visited);
//             }
//         }
//     }

//     void BFS(int node, vector<int> &ans, unordered_map<int, bool> &visited)
//     {

//         queue<int> q;
//         q.push(node);

//         visited[node] = true;

//         while (!q.empty())
//         {
//             int temp = q.front();
//             q.pop();

//             ans.push_back(temp);

//             for (auto i : Adj[temp])
//             {
//                 if (!visited[i])
//                 {
//                     q.push(i);
//                     visited[i] = true;
//                 }
//             }
//         }
//     }
// };
// int main()
// {

//     int n;
//     cout << "Enter the number of vertices : ";
//     cin >> n;

//     int m;
//     cout << "Enter the number of edges : ";
//     cin >> m;

//     graph g;
//     for (int i = 0; i < m; i++)
//     {
//         int u;
//         cin >> u;

//         int v;
//         cin >> v;

//         g.CreateGraph(u, v);
//     }

//     vector<vector<int> > res;
//     unordered_map<int, bool> visited;

//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             vector<int> ans;
//             g.DFS(i, ans, visited);
//             res.push_back(ans);
//         }
//     }

//     for (auto i : res)
//     {
//         for (auto j : i)
//         {
//             cout << j << " ";
//         }
//         cout << endl;
//     }

//     vector<int> ans;
//     unordered_map<int, bool> visited1;

//     for (int i = 0; i < n; i++)
//     {
//         if (!visited1[i])
//         {
//             g.BFS(i, ans, visited1);
//         }
//     }

//     for (auto j : ans)
//     {
//         cout << j << " ";
//     }
//     cout << endl;

//     return 0;
// }

// #include <iostream>
// #include <unordered_map>
// #include <queue>
// #include <list>
// #include <vector>
// using namespace std;
// class graph
// {
// public:
//     unordered_map<int, list<int> > Adj;

//     void CreateGraph(int u, int v)
//     {
//         Adj[u].push_back(v);
//         Adj[v].push_back(u);
//     }

//     void BFS(int node, vector<int> &ans, unordered_map<int, bool> &visited)
//     {
//         queue<int> q;
//         q.push(node);
//         visited[node] = true;

//         while (!q.empty())
//         {
//             int temp = q.front();
//             q.pop();

//             ans.push_back(temp);

//             for (auto i : Adj[node])
//             {
//                 if (!visited[i])
//                 {
//                     visited[i] = true;
//                     q.push(i);
//                 }
//             }
//         }
//     }

//     void DFS(int node, vector<int> &ans, unordered_map<int, bool> &visited)
//     {
//         ans.push_back(node);
//         visited[node] = true;

//         for (auto i : Adj[node])
//         {
//             if (!visited[i])
//             {
//                 DFS(i, ans, visited);
//             }
//         }
//     }
// };
// int main()
// {
//     int n;
//     cin >> n;
//     int m;
//     cin >> m;

//     graph g;
//     for (int i = 0; i < m; i++)
//     {
//         int u;
//         cin >> u;

//         int v;
//         cin >> v;

//         g.CreateGraph(u, v);
//     }

//     unordered_map<int, bool> visited;
//     vector<int> ans;

//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             g.BFS(i, ans, visited);
//         }
//     }

//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
//     cout << endl;

//     unordered_map<int, bool> visited1;
//     vector<int> ans1;

//     for (int i = 0; i < n; i++)
//     {
//         if (!visited1[i])
//         {
//             g.DFS(i, ans1, visited1);
//         }
//     }

//     for (int i = 0; i < ans1.size(); i++)
//     {
//         cout << ans1[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

// #include <iostream>
// #include <unordered_map>
// #include <vector>
// #include <limits.h>
// using namespace std;
// int main()
// {
//     int n;
//     cout << "Enter no of vertices : ";
//     cin >> n;

//     int m;
//     cout << "Enter no of edges : ";
//     cin >> m;

//     unordered_map<int, vector<pair<int, int> > > adj;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back(make_pair(v, w));
//         adj[v].push_back(make_pair(u, w));
//     }

//     vector<int> key(n);
//     vector<int> parent(n);
//     vector<bool> mst(n);

//     for (int i = 0; i < n; i++)
//     {
//         key[i] = INT_MAX;
//         parent[i] = -1;
//         mst[i] = false;
//     }

//     key[0] = 0;
//     parent[0] = -1;

//     for (int i = 0; i < n; i++)
//     {
//         int mini = INT_MAX;
//         int u;
//         for (int i = 0; i < n; i++)
//         {
//             if (mst[i] == false && key[i] < mini)
//             {
//                 mini = key[i];
//                 u = i;
//             }
//         }

//         mst[u] = true;

//         for (auto neighbour : adj[u])
//         {
//             int v = neighbour.first;
//             int w = neighbour.second;

//             if (mst[v] == false && w < key[v])
//             {
//                 parent[v] = u;
//                 key[v] = w;
//             }
//         }
//     }

//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += key[i];
//     }

//     cout << "Minimum Spanning Tree : " << sum << endl;

//     vector<pair<int, pair<int, int> > > result;
//     for (int i = 0; i < n; i++)
//     {
//         result.push_back(make_pair(key[i], make_pair(parent[i], i)));
//     }

//     for (auto i : result)
//     {
//         cout << "u : " << i.second.first << " v : " << i.second.second << " w : " << i.first << endl;
//     }

//     return 0;
// }

// #include <iostream>
// #include <unordered_map>
// #include <vector>
// #include <limits.h>
// #include <set>
// using namespace std;
// int main()
// {
//     int n;
//     cout << "Enter no of vertices : ";
//     cin >> n;
//     int m;
//     cout << "Enter no of edges : ";
//     cin >> m;

//     unordered_map<int, vector<pair<int, int> > > adj;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         adj[u].push_back(make_pair(v, w));
//         adj[v].push_back(make_pair(u, w));
//     }

//     set<pair<int, int> > st;
//     vector<int> distance(n);

//     for (int i = 0; i < n; i++)
//     {
//         distance[i] = INT_MAX;
//     }

//     int Source;
//     cout << "Enter Source : ";
//     cin >> Source;

//     distance[Source] = 0;
//     st.insert(make_pair(distance[Source], Source));

//     while (!st.empty())
//     {

//         auto FirstNode = *(st.begin());

//         int nodeDistance = FirstNode.first;
//         int topNode = FirstNode.second;

//         st.erase(st.begin());

//         for (auto neighbour : adj[topNode])
//         {

//             int v = neighbour.first;
//             int w = neighbour.second;

//             if (nodeDistance + w < distance[v])
//             {
//                 auto record = st.find(make_pair(distance[v], v));

//                 if (record != st.end())
//                 {
//                     st.erase(record);
//                 }

//                 distance[v] = nodeDistance + w;
//                 st.insert(make_pair(distance[v], v));
//             }
//         }
//     }

//     for (auto it : distance)
//     {
//         cout << it << " ";
//     }
//     cout << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }

    return parent[node] = findParent(parent, parent[node]);
}
void UnionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
int Kruskal(vector<vector<int> > &edges, int n)
{
    // Sorting First
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n);
    vector<int> rank(n);

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    int minWeight = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int w = edges[i][2];

        if (u != v)
        {
            minWeight += w;
            UnionSet(u, v, parent, rank);
        }
    }

    return minWeight;
}
int main()
{
    int n;
    cout << "Enter number of vertices : ";
    cin >> n;

    int m;
    cout << "Enter number of edges : ";
    cin >> m;

    vector<vector<int> > edges;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        int u, v, w;
        cin >> u >> v >> w;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(w);

        edges.push_back(temp);
    }

    int weight = Kruskal(edges, n);
    cout << "Weight of mst is : " << weight << endl;
    return 0;
}