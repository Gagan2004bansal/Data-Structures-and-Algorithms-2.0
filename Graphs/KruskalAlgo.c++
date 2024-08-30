#include <iostream>
#include <vector>
using namespace std;
bool compare(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
void makeSet(vector<int> &parent, vector<int> rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int findparent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }

    return parent[node] = findparent(parent, parent[node]);
}
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findparent(parent, u);
    v = findparent(parent, v);

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
int minimumSpanningTree(int n, vector<vector<int> > &edges)
{
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minWeight = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = findparent(parent, edges[i][0]);
        int v = findparent(parent, edges[i][1]);
        int w = edges[i][2];

        if (u != v)
        {
            minWeight += w;
            unionSet(u, v, parent, rank);
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

    int minWeight = minimumSpanningTree(n, edges);
    cout << "Min weight of spanning Tree : " << minWeight << endl;

    return 0;
}