// link : https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands

#include <iostream>
#include <vector>
#include <set>
using namespace std;
void dfs(int row, int col, vector<pair<int, int> > &temp, int delrow[], int delcol[], vector<vector<int> > &grid, vector<vector<int> > &vis, int BaseRow, int BaseCol)
{
    vis[row][col] = 1;
    temp.push_back(make_pair(row - BaseRow, col - BaseCol));

    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, temp, delrow, delcol, grid, vis, row, col);
        }
    }
}
int solve(vector<vector<int> > &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> > vis(n, vector<int>(m, 0));

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};
    set<vector<pair<int, int> > > st;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int> > temp;
                dfs(i, j, temp, delrow, delcol, grid, vis, i, j);
                st.insert(temp);
            }
        }
    }

    return st.size();
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
    cout << "Distinct Island : " << ans << endl;
    return 0;
}