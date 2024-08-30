#include <iostream>
#include <vector>
using namespace std;
int solveUsingRec(int n, int target, vector<int> &arr)
{
    if (target == 0)
    {
        return 1;
    }
    if (target < 0)
    {
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += solveUsingRec(n, target - arr[i], arr);
    }

    return ans;
}

int solveUsingMemo(int n, int target, vector<int> &arr, vector<int> &dp)
{
    // Base Case
    if (target == 0)
    {
        return 1;
    }
    if (target < 0)
    {
        return 0;
    }

    if (dp[target] != -1)
    {
        return dp[target];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += solveUsingMemo(n, target - arr[i], arr, dp);
    }

    dp[target] = ans;
    return dp[target];
}
int solveUsingTabu(int n, int target, vector<int> &arr)
{
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - arr[j] >= 0)
            {
                dp[i] += dp[i - arr[j]];
            }
        }
    }

    return dp[target];
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

    int target;
    cin >> target;

    cout << solveUsingRec(n, target, arr) << endl;

    vector<int> dp(target + 1, -1);
    cout << solveUsingMemo(n, target, arr, dp) << endl;

    cout << solveUsingTabu(n, target, arr) << endl;
    return 0;
}