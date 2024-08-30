#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <limits.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of vertices : ";
    cin >> n;

    int m;
    cout << "Enter number of edges : ";
    cin >> m;

    unordered_map<int, vector<pair<int, int> > > adj;
    for (int i = 0; i < m; i++)
    {
        int u;
        cin >> u;

        int v;
        cin >> v;

        int w;
        cin >> w;

        adj[u].push_back(make_pair(v, w));
        // adj[v].push_back(make_pair(u, w));
    }

    int source;
    cout << "Enter the source : ";
    cin >> source;

    vector<int> dist(n);
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }

    set<pair<int, int> > s;
    s.insert(make_pair(0, source));

    dist[source] = 0;

    while (!s.empty())
    {
        auto topRecord = *(s.begin());

        int nodeDistance = topRecord.first;
        int topNode = topRecord.second;

        s.erase(s.begin());

        for (auto neighbour : adj[topNode])
        {
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = s.find(make_pair(dist[neighbour.first], neighbour.first));

                if (record != s.end())
                {
                    s.erase(record);
                }

                dist[neighbour.first] = nodeDistance + neighbour.second;
                s.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    cout << "Shortest Distance by Dijkstra Algorithms \n";
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}