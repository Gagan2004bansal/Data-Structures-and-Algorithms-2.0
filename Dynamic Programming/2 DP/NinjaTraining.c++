// link : https://www.naukri.com/code360/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <iostream>
#include <vector>
using namespace std;
int solveUsingRecursion(int day, int last, vector<vector<int> > &points)
{
    // Base Case
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[day][i]);
            }
        }
        return maxi;
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + solveUsingRecursion(day - 1, i, points);
            maxi = max(point, maxi);
        }
    }

    return maxi;
}
int solveUsingRecMemo(int day, int last, vector<vector<int> > &points, vector<vector<int> > &dp)
{
    // Base Condition
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[day][i]);
            }
        }
        return maxi;
    }
    // Dp Check
    if (dp[day][last] != -1)
    {
        return dp[day][last];
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + solveUsingRecMemo(day - 1, i, points, dp);
            maxi = max(maxi, point);
        }
    }

    return dp[day][last] = maxi;
}
int solveUsingTabuSO(int n, vector<vector<int> > &points)
{
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][1]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (last != task)
                {
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }

    return prev[3];
}
int main()
{
    int n;
    cout << "Enter no of days : ";
    cin >> n;

    vector<vector<int> > points;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 3; j++)
        {
            int input;
            cin >> input;
            temp.push_back(input);
        }
        points.push_back(temp);
    }

    int ans = solveUsingRecursion(n - 1, 3, points);
    cout << "Max Points using Recursion : " << ans << endl;

    vector<vector<int> > dp(n + 1, vector<int>(4, -1));
    int result = solveUsingRecMemo(n - 1, 3, points, dp);
    cout << "Max Points using Recursion + Memorization : " << result << endl;

    int output = solveUsingTabuSO(n, points);
    cout << "Max Points using Tabulation + Space Opt : " << output << endl;

    return 0;
}