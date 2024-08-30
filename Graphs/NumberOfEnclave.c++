// link: https://leetcode.com/problems/number-of-enclaves/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int solve(vector<vector<int> > &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int> > vis(n, vector<int>(m, 0));
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    queue<pair<int, int> > q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                if (grid[i][j] == 1)
                {
                    vis[i][j] = 1;
                    q.push(make_pair(i, j));
                }
            }
        }
    }

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
            {
                q.push(make_pair(nrow, ncol));
                vis[nrow][ncol] = 1;
            }
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                count++;
            }
        }
    }

    return count;
}
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;

    vector<vector<int> > grid;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int input;
            cin >> input;

            temp.push_back(input);
        }
        grid.push_back(temp);
    }

    int ans = solve(grid);
    cout << "Number of Enclave : " << ans << endl;
    return 0;
}
