#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;
void toposort(int node, unordered_map<int, bool> &visited, stack<int> &st, unordered_map<int, vector<int> > &adj)
{
    visited[node] = true;

    for (auto nbr : adj[node])
    {
        if (!visited[nbr])
        {
            toposort(nbr, visited, st, adj);
        }
    }

    st.push(node);
}
void dfs(int node, unordered_map<int, vector<int> > &transposeList, unordered_map<int, bool> &visited, vector<int> &temp)
{
    visited[node] = true;
    temp.push_back(node);

    for (auto nbr : transposeList[node])
    {
        if (!visited[nbr])
        {
            dfs(nbr, transposeList, visited, temp);
        }
    }
}
int main()
{
    int n;
    cout << "Enter the number of vertices : ";
    cin >> n;

    int m;
    cout << "Enter the number of edges : ";
    cin >> m;

    unordered_map<int, vector<int> > adj;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // First Step -> Toposort
    stack<int> st;
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            toposort(i, visited, st, adj);
        }
    }

    // Second Step -> Transpose
    unordered_map<int, vector<int> > transposeList;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;

        for (auto nbr : adj[i])
        {
            transposeList[nbr].push_back(i);
        }
    }

    // DFS stack wise
    int count = 0;
    vector<vector<int> > res;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        vector<int> temp;

        if (!visited[top])
        {
            count++;
            dfs(top, transposeList, visited, temp);
            res.push_back(temp);
        }
    }

    cout << "Strongly Connected Components : " << count << endl;

    for (auto it : res)
    {
        for (auto j : it)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}