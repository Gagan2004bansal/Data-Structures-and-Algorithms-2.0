//  #include <iostream>
// #include <vector>
// using namespace std;
// void solve(int sr, int sc, int color, int ic, vector<vector<int> > &image, vector<vector<int> > &ans, int delrow[], int delcol[])
// {

//     int n = image.size();
//     int m = image[0].size();

//     ans[sr][sc] = color;

//     for (int i = 0; i < 4; i++)
//     {
//         int nrow = sr + delrow[i];
//         int ncol = sc + delcol[i];

//         if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == ic && ans[nrow][ncol] != color)
//         {
//             solve(nrow, ncol, color, ic, image, ans, delrow, delcol);
//         }
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int m;
//     cin >> m;

//     vector<vector<int> > image;
//     for (int i = 0; i < n; i++)
//     {
//         vector<int> temp;
//         for (int j = 0; j < m; j++)
//         {
//             int input;
//             cin >> input;

//             temp.push_back(input);
//         }
//         image.push_back(temp);
//     }

//     int sr, sc, color;
//     cout << "Enter Sr, Sc and Color : ";
//     cin >> sr >> sc >> color;

//     int ic = image[sr][sc];
//     vector<vector<int> > ans = image;

//     int delrow[4] = {0, -1, 0, 1};
//     int delcol[4] = {-1, 0, 1, 0};

//     solve(sr, sc, color, ic, image, ans, delrow, delcol);

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cout << ans[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if it is possible to find a valid path with max value <= X
bool canReachWithMaxValue(const vector<int> &A, const vector<int> &B, int X) {
    int N = A.size();
    vector<bool> dpA(N, false), dpB(N, false);

    // Initialize the base case
    dpA[0] = (A[0] <= X);
    dpB[0] = (B[0] <= X);

    // Fill the DP arrays
    for (int j = 1; j < N; j++) {
        if (A[j] <= X) {
            dpA[j] = dpA[j-1] || dpB[j-1];
        }
        if (B[j] <= X) {
            dpB[j] = dpB[j-1] || dpA[j-1];
        }
    }

    // Check if we can reach the last element
    return dpA[N-1] || dpB[N-1];
}

int solution(vector<int> &A, vector<int> &B) {
    int N = A.size();

    // Binary search on the answer (minimum possible max value on a valid path)
    int low = min(*min_element(A.begin(), A.end()), *min_element(B.begin(), B.end()));
    int high = max(*max_element(A.begin(), A.end()), *max_element(B.begin(), B.end()));

    while (low < high) {
        int mid = (low + high) / 2;

        if (canReachWithMaxValue(A, B, mid)) {
            high = mid; // Try a smaller maximum value
        } else {
            low = mid + 1; // Increase the minimum possible value
        }
    }

    return low; // The minimum possible maximum value on a valid path
}

int main() {
    vector<int> A1 = {3, 4, 6};
    vector<int> B1 = {6, 5, 4};
    cout << "Expected: 5, Result: " << solution(A1, B1) << endl;

    vector<int> A2 = {1, 2, 1, 1, 1, 4};
    vector<int> B2 = {1, 1, 1, 3, 1, 1};
    cout << "Expected: 2, Result: " << solution(A2, B2) << endl;

    vector<int> A3 = {-5, -1, -3};
    vector<int> B3 = {-5, 5, -2};
    cout << "Expected: -1, Result: " << solution(A3, B3) << endl;

    return 0;
}