// Rat in a Maze
// #include <iostream>
// #include <vector>
// using namespace std;
// void solve(vector<vector<int> > &arr, vector<string> &res, string str, int &count, int row, int col, int n)
// {
//     if (row == n - 1 && col == n - 1)
//     {
//         res.push_back(str);
//         count++;
//         return;
//     }

//     string Direction = "URDL";
//     int delrow[] = {-1, 0, 1, 0};
//     int delcol[] = {0, 1, 0, -1};

//     arr[row][col] = 0;

//     for (int i = 0; i < 4; i++)
//     {
//         int nrow = row + delrow[i];
//         int ncol = col + delcol[i];

//         if (nrow >= 0 && ncol >= 0 && nrow < n && nrow < n && arr[nrow][ncol])
//         {
//             str += Direction[i];
//             solve(arr, res, str, count, nrow, ncol, n);
//             str.pop_back();
//         }
//     }

//     arr[row][col] = 1;
// }
// int main()
// {
//     int n;
//     cin >> n;

//     vector<vector<int> > arr;
//     for (int i = 0; i < n; i++)
//     {
//         vector<int> temp;
//         for (int j = 0; j < n; j++)
//         {
//             int input;
//             cin >> input;

//             temp.push_back(input);
//         }
//         arr.push_back(temp);
//     }

//     vector<string> res;
//     int count = 0;
//     string str = "";

//     solve(arr, res, str, count, 0, 0, n);

//     cout << "Total Possible Case : " << count << endl;

//     for (auto i : res)
//     {
//         cout << i << endl;
//     }
//     return 0;
// }

// Subset or Subsequences equal to Target
// #include <iostream>
// #include <vector>
// using namespace std;
// void Show(vector<int> temp)
// {
//     for (int i = 0; i < temp.size(); i++)
//     {
//         cout << temp[i] << " ";
//     }
//     cout << endl;
// }
// void solve(vector<int> &arr, int index, int n, int k, int &count, int sum, vector<int> &temp)
// {
//     if (temp.size() != 0)
//     {
//         if (sum == k)
//         {
//             count++;
//             Show(temp);
//         }
//     }

//     for (int i = index; i < n; i++)
//     {
//         temp.push_back(arr[i]);
//         sum += arr[i];
//         solve(arr, i + 1, n, k, count, sum, temp);
//         sum -= arr[i];
//         temp.pop_back();
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> arr;
//     for (int i = 0; i < n; i++)
//     {
//         int input;
//         cin >> input;
//         arr.push_back(input);
//     }

//     int k;
//     cin >> k;

//     int count = 0;
//     vector<int> temp;
//     solve(arr, 0, n, k, count, 0, temp);

//     cout << "Total Possible Subset / Subsequence to Target : " << count << endl;

//     return 0;
// }

// N Queen
// #include <iostream>
// #include <vector>
// using namespace std;
// bool isSafe(vector<string> &chess, int row, int col, int n)
// {
//     // col check
//     for (int i = 0; i < col; i++)
//     {
//         if (chess[row][i] == 'Q')
//         {
//             return false;
//         }
//     }
//     // Diagonal check
//     for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
//     {
//         if (chess[i][j] == 'Q')
//         {
//             return false;
//         }
//     }
//     // Anti - Diagonal Check
//     for (int i = row, j = col; i < n && j >= 0; i++, j--)
//     {
//         if (chess[i][j] == 'Q')
//         {
//             return false;
//         }
//     }
//     return true;
// }
// void solve(vector<string> &chess, vector<vector<string> > &ans, int col, int n, int &count)
// {
//     if (col >= n)
//     {
//         count++;
//         ans.push_back(chess);
//     }

//     for (int row = 0; row < n; row++)
//     {
//         if (isSafe(chess, row, col, n))
//         {
//             chess[row][col] = 'Q';
//             solve(chess, ans, col + 1, n, count);
//             chess[row][col] = '.';
//         }
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;

//     vector<string> chess;
//     for (int i = 0; i < n; i++)
//     {
//         string temp = "";
//         for (int j = 0; j < n; j++)
//         {
//             temp += '.';
//         }
//         chess.push_back(temp);
//     }

//     vector<vector<string> > ans;
//     int count = 0;

//     solve(chess, ans, 0, n, count);
//     cout << "Total Possible ways : " << count << endl;

//     for (auto i : ans)
//     {
//         for (auto j : i)
//         {
//             cout << j << endl;
//         }
//         cout << endl;
//     }

//     return 0;
// }

// Generate Paranthesis
// #include <iostream>
// #include <vector>
// using namespace std;
// void solve(vector<string> &ans, string path, int left, int right)
// {
//     if (left == 0 && right == 0)
//     {
//         ans.push_back(path);
//         return;
//     }

//     if (left > right || left < 0 || right < 0)
//     {
//         return;
//     }

//     path.push_back('(');
//     solve(ans, path, left - 1, right);
//     path.pop_back();

//     path.push_back(')');
//     solve(ans, path, left, right - 1);
//     path.pop_back();

//     return;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     vector<string> ans;
//     string path = "";
//     solve(ans, path, n, n);

//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;
void Show(vector<vector<int> > &Temp)
{
    cout << endl;
    for (int i = 0; i < Temp.size(); i++)
    {
        for (int j = 0; j < Temp.size(); j++)
        {
            cout << Temp[i][j] << " ";
        }
        cout << endl;
    }
}
void solve(vector<vector<int> > &arr, vector<vector<int> > &Temp, int row, int col, int n)
{
    if (row == n - 1 && col == n - 1)
    {
        Show(Temp);
        exit(0);
    }

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    arr[row][col] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow >= 0 && ncol >= 0 && nrow < n && nrow < n && arr[nrow][ncol])
        {
            Temp[nrow][ncol] = 1;
            solve(arr, Temp, nrow, ncol, n);
            Temp[nrow][ncol] = 0;
        }
    }
    arr[row][col] = 1;
}
int main()
{
    int n;
    cin >> n;

    vector<vector<int> > arr;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int input;
            cin >> input;

            temp.push_back(input);
        }
        arr.push_back(temp);
    }

    vector<vector<int> > Temp(n, vector<int>(n, 0));

    Temp[0][0] = 1;
    if (arr[0][0] == 1)
    {
        solve(arr, Temp, 0, 0, n);
    }

    cout << "No Path Found" << endl;

    return 0;
}