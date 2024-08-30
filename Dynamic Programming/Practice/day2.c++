#include <iostream>
#include <vector>
using namespace std;
int solveUsingRec(int n)
{
    // Base Case
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    // Condition
    int ans = (n - 1) * (solveUsingRec(n - 2) + solveUsingRec(n - 1));
    return ans;
}
int solveUsingMemo(int n, vector<int> &dp)
{
    // Base Case
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (n - 1) * (solveUsingMemo(n - 2, dp) + solveUsingMemo(n - 1, dp));
    return dp[n];
}
int solveUsingTabu(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        int first = dp[i - 1];
        int second = dp[i - 2];
        int sum = first + second;
        int ans = (i - 1) * (sum);
        dp[i] = ans;
    }

    return dp[n];
}
int solveUsingSO(int n)
{
    int prev1 = 1;
    int prev2 = 0;

    for (int i = 3; i <= n; i++)
    {
        int first = prev1;
        int second = prev2;
        int sum = first + second;
        int ans = (i - 1) * sum;
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}
int main()
{
    int n;
    cout << "Enter number : ";
    cin >> n;

    cout << "Solve using recursion : " << solveUsingRec(n) << endl;

    vector<int> dp(n + 1, -1);
    cout << "Solve using Memo : " << solveUsingMemo(n, dp) << endl;

    cout << "Solve using Tabulation : " << solveUsingTabu(n) << endl;

    cout << "Solve using Tabulation + Space Optimize : " << solveUsingSO(n) << endl;

    return 0;
}