#include <iostream>
#include <vector>
using namespace std;
int solveUsingRecursion(int n, int amount, vector<int> &arr)
{
    if (amount <= 0)
    {
        return 0;
    }

    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (amount - arr[i] >= 0)
        {
            int ans = solveUsingRecursion(n, amount - arr[i], arr);
            if (ans != INT_MAX)
            {
                ans = ans + 1;
                mini = min(mini, ans);
            }
        }
    }

    return mini;
}
int solveUsingMemo(int n, int amount, vector<int> &dp, vector<int> &arr)
{
    // Base Case
    if (amount <= 0)
    {
        return 0;
    }

    if (dp[amount] != -1)
    {
        return dp[amount];
    }

    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (amount - arr[i] >= 0)
        {
            int ans = solveUsingMemo(n, amount - arr[i], dp, arr);
            if (ans != INT_MAX)
            {
                ans = ans + 1;
                mini = min(mini, ans);
            }
        }
    }

    dp[amount] = mini;
    return dp[amount];
}
int solveUsingTabu(int n, int amount, vector<int> &arr)
{
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        int mini = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            if (amount - arr[i] >= 0)
            {
                int ans = dp[i - arr[j]];
                if (ans != INT_MAX)
                {
                    ans += 1;
                    mini = min(mini, ans);
                }
            }
        }
        dp[i] = mini;
    }

    return dp[amount];
}
int main()
{
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        arr.push_back(input);
    }

    int amount;
    cin >> amount;

    int ans = solveUsingRecursion(n, amount, arr);
    cout << ans << endl;

    vector<int> dp(amount + 1, -1);
    cout << solveUsingMemo(n, amount, dp, arr) << endl;

    cout << solveUsingTabu(n, amount, arr) << endl;

    return 0;
}