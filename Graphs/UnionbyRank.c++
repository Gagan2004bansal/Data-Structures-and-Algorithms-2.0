#include <iostream>
#include <vector>
using namespace std;
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int findparent(int node, vector<int> &parent)
{
    if (parent[node] == node)
    {
        return node;
    }

    return parent[node] = findparent(parent[node], parent);
}
void UnionSet(int n, vector<int> &nodes, vector<vector<int> > &queries)
{
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    for (int i = 0; i < queries.size(); i++)
    {
        int u = findparent(queries[i][0], parent);
        int v = findparent(queries[i][1], parent);

        int uRank = rank[u];
        int vRank = rank[v];

        if (uRank < vRank)
        {
            parent[u] = v;
        }
        else if (vRank < uRank)
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    cout << "Parent of every node \n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : " << parent[i] << endl;
    }
}
int main()
{
    int n;
    cout << "Enter number of vertices : ";
    cin >> n;

    vector<int> nodes(n);
    cout << "Enter the nodes \n";
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;
        nodes.push_back(u);
    }

    int m;
    cout << "Enter number of queries : ";
    cin >> m;

    vector<vector<int> > queries;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        int u, v;
        cin >> u >> v;
        temp.push_back(u);
        temp.push_back(v);

        queries.push_back(temp);
    }

    UnionSet(n, nodes, queries);

    return 0;
}