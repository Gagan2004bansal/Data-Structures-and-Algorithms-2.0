#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool bfs(int source, vector<vector<int> > &adj, vector<int> &colored)
{
    queue<int> q;
    q.push(source);
    int color = 0;
    colored[source] = color;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto nbr : adj[node])
        {
            if (colored[nbr] == -1)
            {
                colored[nbr] = !colored[node];
                q.push(nbr);
            }
            else
            {
                if (colored[nbr] == colored[node])
                {
                    return false;
                }
            }
        }
    }

    return true;
}
bool dfs(int source, vector<vector<int> > &adj, vector<int> &colored1, int color)
{
    colored1[source] = color;

    for (auto nbr : adj[source])
    {
        if (colored1[nbr] == -1)
        {
            colored1[nbr] = !colored1[source];
            bool ans = dfs(source, adj, colored1, !color);
            if (ans == false)
            {
                return false;
            }
        }
        else
        {
            if (colored1[source] == colored1[nbr])
            {
                return false;
            }
        }
    }

    return true;
}
int main()
{
    int n;
    cin >> n;

    int m;

    vector<vector<int> > adj;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int input;
            cin >> input;

            temp.push_back(input);
        }
        adj.push_back(temp);
    }

    vector<int> colored(n, -1);

    bool ans;
    for (int i = 0; i < n; i++)
    {
        if (colored[i] == -1)
        {
            ans = bfs(i, adj, colored);
            if (ans == false)
            {
                cout << "Not a biparite Graph" << endl;
                break;
            }
        }
    }
    if (ans)
    {
        cout << "Biparite Graph" << endl;
    }

    // vector<int> colored1(n, -1);
    // bool ans1;
    // for (int i = 0; i < n; i++)
    // {
    //     if (colored1[i] == -1)
    //     {
    //         ans1 = dfs(i, adj, colored1, 0);
    //         if (ans1 == false)
    //         {
    //             cout << "Not a biparite Graph" << endl;
    //             break;
    //         }
    //     }
    // }
    // if (ans1)
    // {
    //     cout << "Biparite Graph" << endl;
    // }

    return 0;
}
// [[1,2,3],[0,2],[0,1,3],[0,2]]
// [[1,3],[0,2],[1,3],[0,2]]