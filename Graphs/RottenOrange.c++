// link : https://leetcode.com/problems/rotting-oranges/description/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int solve(vector<vector<int> > &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int vis[n][m];
    queue<pair<pair<int, int>, int> > q;
    int Fresh = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                vis[i][j] = 2;
                q.push(make_pair(make_pair(i, j), 0));
            }
            else
            {
                vis[i][j] = 0;
            }

            if (grid[i][j] == 1)
            {
                Fresh++;
            }
        }
    }

    int t = 0;
    int count = 0;
    int delrow[] = {0, -1, 0, 1};
    int delcol[] = {-1, 0, 1, 0};

    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;

        t = max(t, time);

        q.pop(); // pop Important --> TLE

        for (int i = 0; i < 4; i++)
        {

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2)
            {
                q.push(make_pair(make_pair(nrow, ncol), t + 1));
                vis[nrow][ncol] = 2;
                count++;
            }
        }
    }

    if (count != Fresh)
    {
        return -1;
    }

    return t;
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
    cout << "Time : " << ans << endl;
    return 0;
}