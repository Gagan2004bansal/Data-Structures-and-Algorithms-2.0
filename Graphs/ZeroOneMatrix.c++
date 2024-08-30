// link : https://leetcode.com/problems/01-matrix/description/?source=submission-ac

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int> > solve(vector<vector<int> > &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int> > distance(n, vector<int>(m, 0));
    vector<vector<int> > visited(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int> > q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push(make_pair(make_pair(i, j), 0));
                visited[i][j] = 1;
            }
            else
            {
                visited[i][j] = 0;
            }
        }
    }

    int delcol[] = {-1, 0, 1, 0};
    int delrow[] = {0, -1, 0, 1};

    while (!q.empty())
    {

        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;

        distance[row][col] = steps;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0)
            {
                q.push(make_pair(make_pair(nrow, ncol), steps + 1));
                visited[nrow][ncol] = 1;
            }
        }
    }

    return distance;
}
int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<vector<int> > mat;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int input;
            cin >> input;

            temp.push_back(input);
        }

        mat.push_back(temp);
    }

    vector<vector<int> > ans = solve(mat);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}