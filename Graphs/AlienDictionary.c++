#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> Toposort(int k, vector<int> adj[])
{
    vector<int> Indegree(k);
    for (int i = 0; i < k; i++)
    {
        for (auto nbr : adj[i])
        {
            Indegree[nbr]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < Indegree.size(); i++)
    {
        if (Indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> temp;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        temp.push_back(node);

        for (auto nbr : adj[node])
        {
            Indegree[nbr]--;
            if (Indegree[nbr] == 0)
            {
                q.push(nbr);
            }
        }
    }

    return temp;
}
int main()
{
    int n;
    cin >> n;
    vector<string> dict;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        dict.push_back(str);
    }
    int k;
    cin >> k;

    // Solution
    vector<int> adj[k];
    for (int i = 0; i < n - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.length(), s2.length());
        for (int j = 0; j < len; j++)
        {
            if (s1[j] != s2[j])
            {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }

    vector<int> topo = Toposort(k, adj);
    string ans = "";
    for (auto it : topo)
    {
        ans = ans + char(it + 'a');
    }

    cout << ans << endl;
    return 0;
}

// N = 5, K = 4
// dict = {"baa","abcd","abca","cab","cad"}