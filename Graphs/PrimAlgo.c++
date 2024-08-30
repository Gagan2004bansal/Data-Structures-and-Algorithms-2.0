// Finding minimum spanning Tree
// Note here solution is done on 0-based indexing
#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;

    int m;
    cout << "Enter number of edges : ";
    cin >> m;

    // Creating adajency Matrix
    unordered_map<int, vector<pair<int, int> > > adj;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Initializing Vector
    vector<int> key(n);
    vector<bool> mst(n);
    vector<int> parent(n);

    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    parent[0] = -1;
    key[0] = 0;

    for (int i = 0; i < n; i++)
    {
        // finding minimum value
        int mini = INT_MAX;
        int u;

        for (int v = 0; v < n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // Marking mst to true
        mst[u] = true;

        // then Finding it adjacent nodes
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < key.size(); i++)
    {
        sum += key[i];
    }

    cout << "Spaning Tree weight is " << sum << endl;

    // if it said to make spaning Tree
    vector<pair<int, pair<int, int> > > result;
    for (int i = 0; i < n; i++)
    {
        result.push_back(make_pair(i, make_pair(parent[i], key[i])));
    }

    for (auto i : result)
    {
        int u = i.first;
        int v = i.second.first;
        int w = i.second.second;

        cout << u << " " << v << " " << w << endl;
    }

    return 0;
}

// Currently T.C is N^2

// Use MinHeap to find miniumn to reduce T.C to nlogn
// Do this when you revise Heap