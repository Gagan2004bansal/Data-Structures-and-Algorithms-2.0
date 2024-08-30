#include <iostream>
#include <vector>
using namespace std;
int solveUsingRec(int n)
{
    // Base Case
    if (n == 0)
    {
        return 0;
    }

    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        int temp = i * i;
        ans = min(ans, 1 + solveUsingRec(n - temp));
    }

    return ans;
}
int solveUsingMemo(int n, vector<int> &dp)
{
    // Base Case
    if (n == 0)
    {
        return 0;
    }

    // Dp Check
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        int temp = i * i;
        ans = min(ans, 1 + solveUsingMemo(n - temp, dp));
    }

    dp[n] = ans;
    return dp[n];
}
int solveUsingTabu(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= n; j++)
        {
            int temp = j * j;
            if (i - temp >= 0)
            {
                dp[i] = min(dp[i], 1 + dp[i - temp]);
            }
        }
    }

    return dp[n];
}
int main()
{
    int n;
    cin >> n;

    // cout << solveUsingRec(n) << endl; // Giving TLE

    vector<int> dp(n + 1, -1);
    cout << solveUsingMemo(n, dp) << endl;

    cout << solveUsingTabu(n) << endl;
    return 0;
}