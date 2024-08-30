// Spiral Print of Matrix

// #include <iostream>
// #include <vector>
// using namespace std;
// void solve(vector<vector<int> > &arr, int n, int m)
// {
//     int startRow = 0;
//     int startCol = 0;
//     int endRow = n - 1;
//     int endCol = m - 1;

//     int total = n * m;
//     int count = 0;

//     vector<int> temp;

//     while (count < total)
//     {
//         for (int i = startCol; i <= endCol && count < total; i++)
//         {
//             temp.push_back(arr[startRow][i]);
//             count++;
//         }
//         startRow++;
//         for (int i = startRow; i <= endRow && count < total; i++)
//         {
//             temp.push_back(arr[i][endCol]);
//             count++;
//         }
//         endCol--;
//         for (int i = endCol; i >= startCol && count < total; i--)
//         {
//             temp.push_back(arr[endRow][i]);
//             count++;
//         }
//         endRow--;
//         for (int i = endRow; i >= startRow && count < total; i--)
//         {
//             temp.push_back(arr[i][startCol]);
//             count++;
//         }
//         startCol++;
//     }

//     for (int j = 0; j < temp.size(); j++)
//     {
//         cout << temp[j] << " ";
//     }
//     cout << endl;
// }
// int main()
// {
//     int n;
//     cin >> n;

//     int m;
//     cin >> m;

//     // [[1,2,3,4],[5,6,7,8],[9,10,11,12]]

//     vector<vector<int> > arr;
//     for (int i = 0; i < n; i++)
//     {
//         vector<int> temp;
//         for (int j = 0; j < m; j++)
//         {
//             int input;
//             cin >> input;
//             temp.push_back(input);
//         }
//         arr.push_back(temp);
//     }

//     solve(arr, n, m);

//     return 0;
// }

// Rotate Matrix
// 90 Clockwise
// 90 Anti Clockwise
// 180 Rotate

#include <iostream>
#include <vector>
using namespace std;
void Transpose(vector<vector<int> > &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}
void RowReverse(vector<vector<int> > &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        int e = n - 1;
        while (s < e)
        {
            swap(arr[i][s++], arr[i][e--]);
        }
    }
}
void ColReverse(vector<vector<int> > &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        int e = n - 1;
        while (s < e)
        {
            swap(arr[s++][i], arr[e--][i]);
        }
    }
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

    Transpose(arr, n);
    RowReverse(arr, n);
    // ColReverse(arr, n);

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}