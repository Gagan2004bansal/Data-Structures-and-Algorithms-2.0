#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of vertices : ";
    cin >> n;

    int m;
    cout << "Enter number of edges : ";
    cin >> m;

    vector<vector<int> > adj;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(w);
        adj.push_back(temp);
    }

    int source, desc;
    cout << "Enter Source and Destination \n";
    cin >> source >> desc;

    vector<int> distance(n + 1, 1e9);
    distance[source] = 0;

    // as we are going for 1 based indexing
    // run outer loop to n-1 times
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = adj[j][0];
            int v = adj[j][1];
            int w = adj[j][2];

            if (distance[u] != 1e9 && (distance[u] + w < distance[v]))
            {
                distance[v] = distance[u] + w;
            }
        }
    }

    cout << distance[desc] << endl;
    return 0;
}