#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int solveUsingRec(int n, vector<int> &days, vector<int> &costs, int index)
{
    // Base Case
    if (index >= n)
    {
        return 0;
    }

    // 1 Day Pass
    int option1 = costs[0] + solveUsingRec(n, days, costs, index + 1);

    // 7 Day Pass
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;
    int option2 = costs[1] + solveUsingRec(n, days, costs, i);

    // 30 Day Pass
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;
    int option3 = costs[2] + solveUsingRec(n, days, costs, i);

    return min(option1, min(option2, option3));
}
// int solveUsingMemo() {}
// int solveUsingTabu() {}
int Solve(int n, vector<int> &days, vector<int> &costs)
{
    int ans = 0;

    queue<pair<int, int> > month;
    queue<pair<int, int> > week;

    for (int day : days)
    {
        // Checking Expiring Days
        while (!month.empty() && month.front().first + 30 <= day)
        {
            month.pop();
        }
        while (!week.empty() && week.front().first + 7 <= day)
        {
            week.pop();
        }

        // Ans Updating in Queue
        month.push(make_pair(day, ans + costs[2]));
        week.push(make_pair(day, ans + costs[1]));

        // ans Upadting
        ans = min(ans + costs[0], min(month.front().second, week.front().second));
    }

    return ans;
}
//  [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
int main()
{
    int n;
    cin >> n;
    vector<int> days;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        days.push_back(input);
    }
    vector<int> costs;
    for (int i = 0; i < 3; i++)
    {
        int input;
        cin >> input;
        costs.push_back(input);
    }

    cout << Solve(n, days, costs) << endl;
    cout << solveUsingRec(n, days, costs, 0) << endl;
    return 0;
}