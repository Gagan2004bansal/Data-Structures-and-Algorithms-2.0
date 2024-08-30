// Simple Creation of graph using Vector
// #include <iostream>
// #include <vector>
//     using namespace std;
// vector<vector<int> > CreateGraph(int n, int m, vector<vector<int> > &edges)
// {
//     vector<vector<int> > adjList(n);
//     for (int i = 0; i < m; i++)
//     {
//         int u = edges[i][0];
//         int v = edges[i][1];

//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }

//     return adjList;
// }
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int> > edges(m, vector<int>(2));

//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < 2; j++)
//         {
//             cin >> edges[i][j];
//         }
//     }

//     vector<vector<int> > ans = CreateGraph(n, m, edges);

//     for (int i = 0; i < n; i++)
//     {
//         cout << i << " -> ";
//         for (auto j : ans[i])
//         {
//             cout << j << " , ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// Graph Creation using Unordered Map
// #include <iostream>
// #include <vector>
// #include <unordered_map>
//     using namespace std;
// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     unordered_map<int, vector<int> > adjList;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;

//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }

//     for (auto i : adjList)
//     {
//         cout << i.first << " -> ";
//         for (auto j : i.second)
//         {
//             cout << j << " , ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// DFS Traversal of Graph
// #include <iostream>
// #include <vector>
// #include <unordered_map>
//     using namespace std;
// void DFS(int node, vector<int> &ans, unordered_map<int, bool> &visited, unordered_map<int, vector<int> > &adjList)
// {
//     visited[node] = true;
//     ans.push_back(node);

//     for (auto nbr : adjList[node])
//     {
//         if (!visited[nbr])
//         {
//             DFS(nbr, ans, visited, adjList);
//         }
//     }
// }
// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     unordered_map<int, vector<int> > adjList;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;

//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }

//     unordered_map<int, bool> visited;
//     vector<int> ans;
//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             DFS(i, ans, visited, adjList);
//         }
//     }

//     for (auto i : ans)
//     {
//         cout << i << " ";
//     }
//     cout << endl;

//     return 0;
// }

// // BFS Traversal in Graph
// #include <iostream>
// #include <set>
// #include <vector>
// #include <unordered_map>
// #include <queue>
//     using namespace std;
// void BFS(int node, vector<int> &ans, unordered_map<int, bool> &visited, unordered_map<int, set<int> > &adjList)
// {
//     queue<int> q;
//     q.push(node);
//     visited[node] = true;

//     while (!q.empty())
//     {
//         int temp = q.front();
//         q.pop();

//         ans.push_back(temp);

//         for (auto nbr : adjList[temp])
//         {
//             if (!visited[nbr])
//             {
//                 q.push(nbr);
//                 visited[nbr] = true;
//             }
//         }
//     }
// }
// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     unordered_map<int, set<int> > adjList;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;

//         adjList[u].insert(v);
//         adjList[v].insert(u);
//     }

//     unordered_map<int, bool> visited;
//     vector<int> ans;

//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             BFS(i, ans, visited, adjList);
//         }
//     }

//     for (auto i : ans)
//     {
//         cout << i << " ";
//     }
//     cout << endl;

//     return 0;
// }

//  Shortest Path by Dijkstra's Algorithm
// #include <iostream>
// #include <set>
// #include <unordered_map>
// #include <vector>
// #include <limits.h>
//     using namespace std;
// int main()
// {
//     int n;
//     cout << "Enter the number of vertices : ";
//     cin >> n;

//     int m;
//     cout << "Enter the number of edges : ";
//     cin >> m;

//     unordered_map<int, vector<pair<int, int> > > adjList;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         cin >> u;
//         cin >> v;
//         cin >> w;

//         adjList[u].push_back(make_pair(v, w));
//     }

//     int source;
//     cout << "Enter the source : ";
//     cin >> source;

//     vector<int> distance(n);
//     for (int i = 0; i < n; i++)
//     {
//         distance[i] = INT_MAX;
//     }
//     distance[source] = 0;

//     set<pair<int, int> > st;
//     st.insert(make_pair(0, source));
//     // {distance, node}

//     while (!st.empty())
//     {
//         auto topRecord = *(st.begin());
//         int node = topRecord.second;
//         int dist = topRecord.first;

//         st.erase(st.begin());

//         for (auto nbr : adjList[node])
//         {
//             int v = nbr.first;
//             int w = nbr.second;
//             if (dist + w < distance[v])
//             {
//                 auto record = st.find(make_pair(distance[v], v));
//                 if (record != st.end())
//                 {
//                     st.erase(record);
//                 }

//                 distance[v] = dist + w;
//                 st.insert(make_pair(distance[v], v));
//             }
//         }
//     }

//     cout << "Shortest Distance by Dijkstra Algorithms \n";
//     for (int i = 0; i < distance.size(); i++)
//     {
//         cout << distance[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// Topological Sort
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <stack>
//     using namespace std;
// void TopoSort(int node, stack<int> &st, unordered_map<int, bool> &visited, unordered_map<int, vector<int> > &adjList)
// {
//     visited[node] = true;

//     for (auto nbr : adjList[node])
//     {
//         if (!visited[nbr])
//         {
//             TopoSort(nbr, st, visited, adjList);
//         }
//     }

//     st.push(node);
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int m;
//     cin >> m;

//     unordered_map<int, vector<int> > adjList;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;

//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }

//     stack<int> st;
//     unordered_map<int, bool> visited;
//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             TopoSort(i, st, visited, adjList);
//         }
//     }

//     while (!st.empty())
//     {
//         cout << st.top() << " ";
//         st.pop();
//     }
//     cout << endl;
//     return 0;
// }

// Cycle Detection in Directed Unweighted Graph
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <unordered_map>
//     using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int m;
//     cin >> m;
//     unordered_map<int, vector<int> > adjList;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;

//         adjList[u].push_back(v);
//     }

//     vector<int> Indegree(n);
//     for (auto i : adjList)
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
//         int node = q.front();
//         q.pop();

//         count++;
//         for (auto nbr : adjList[node])
//         {
//             Indegree[nbr]--;
//             if (Indegree[nbr] == 0)
//             {
//                 q.push(nbr);
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

// Cycle Detection in Unidirected Unweighted Graph
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// using namespace std;
// bool CycleDetect(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, vector<int> > &adjList)
// {
//     visited[node] = true;
//     for (auto nbr : adjList[node])
//     {
//         if (!visited[nbr])
//         {
//             bool ans = CycleDetect(nbr, node, visited, adjList);
//             if (ans == true)
//             {
//                return true;
//             }
//         }
//         else if (nbr != parent)
//         {
//             return true;
//         }
//     }

//     return false;
// }
// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     unordered_map<int, vector<int> > adjList;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;

//         adjList[u].push_back(v);
//         adjList[v].push_back(u);
//     }

//     unordered_map<int, bool> visited;
//     bool ans = 0;
//     int parent = -1;
//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             ans = CycleDetect(i, parent, visited, adjList);
//             if (ans == 1)
//             {
//                 cout << "Cycle Detected" << endl;
//                 break;
//             }
//         }
//     }

//     if (ans == 0)
//     {
//         cout << "No Cycle Found" << endl;
//     }

//     return 0;
// }

// Transpose of Graph
// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <map>
//     using namespace std;
// int main()
// {
//     int n;
//     cin >> n;

//     int m;
//     cin >> m;

//     map<int, vector<int> > adjList;
//     for (int i = 0; i < m; i++)
//     {
//         int u;
//         cin >> u;

//         int v;
//         cin >> v;

//         adjList[v].push_back(u);
//     }

//     for (auto i : adjList)
//     {
//         cout << i.first << " -> ";
//         for (auto j : i.second)
//         {
//             cout << j << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
