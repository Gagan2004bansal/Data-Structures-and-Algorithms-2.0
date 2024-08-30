#include <iostream>
#include <vector>
using namespace std;
int solveUsingRecursion(vector<int> &weight, vector<int> &value, int index, int capacity)
{
    // Base Case
    if (index == 0)
    {
        if (weight[index] <= capacity)
        {
            return value[index];
        }
        else
        {
            return 0;
        }
    }

    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveUsingRecursion(weight, value, index - 1, capacity - weight[index]);
    }
    int exclude = 0 + solveUsingRecursion(weight, value, index - 1, capacity);

    int ans = max(include, exclude);
    return ans;
}
int solveUsingMemo(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int> > &dp)
{
    // Base Case
    if (index == 0)
    {
        if (weight[index] <= capacity)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    // Dp Checking
    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveUsingMemo(weight, value, index - 1, capacity - weight[index], dp);
    }

    int exclude = 0 + solveUsingMemo(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}
int solveUsingTabu(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<vector<int> > dp(n, vector<int>(capacity + 1, 0));
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[0][w] = value[0];
        }
        else
        {
            dp[0][w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (weight[index] <= w)
            {
                include = value[index] + dp[index - 1][w - weight[index]];
            }

            int exclude = 0 + dp[index - 1][w];

            dp[index][w] = max(include, exclude);
        }
    }

    return dp[n - 1][capacity];
}
int solveUsingSO(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (weight[index] <= w)
            {
                include = value[index] + prev[w - weight[index]];
            }

            int exclude = 0 + prev[w];

            curr[w] = max(include, exclude);
        }

        prev = curr;
    }

    return prev[capacity];
}
int solveUsingPlusSO(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<int> curr(capacity + 1, 0);
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            curr[w] = value[0];
        }
        else
        {
            curr[w] = 0;
        }
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = capacity; w >= 0; w--)
        {
            int include = 0;
            if (weight[index] <= w)
            {
                include = value[index] + curr[w - weight[index]];
            }

            int exclude = 0 + curr[w];

            curr[w] = max(include, exclude);
        }
    }

    return curr[capacity];
}
int main()
{
    int n;
    cin >> n;

    vector<int> weight;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        weight.push_back(input);
    }
    vector<int> value;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        value.push_back(input);
    }

    int maxWeight;
    cin >> maxWeight;

    cout << solveUsingRecursion(weight, value, n - 1, maxWeight) << endl;

    vector<vector<int> > dp(n, vector<int>(maxWeight + 1, -1));
    cout << solveUsingMemo(weight, value, n - 1, maxWeight, dp) << endl;

    cout << solveUsingTabu(weight, value, n, maxWeight) << endl;

    cout << solveUsingSO(weight, value, n, maxWeight) << endl;

    cout << solveUsingPlusSO(weight, value, n, maxWeight) << endl;

    return 0;
}