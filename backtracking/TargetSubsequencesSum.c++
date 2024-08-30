#include <iostream>
#include <vector>
using namespace std;

void Show(vector<int> temp)
{
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}

void Solve(vector<int> &arr, int index, vector<int> &temp, int ans, int sum, int &count)
{
    // Base Case
    if (temp.size() != 0)
    {
        if (ans == sum)
        {
            Show(temp);
            count++;
        }
    }

    for (int i = index; i < arr.size(); i++)
    {
        temp.push_back(arr[i]);
        ans += arr[i];
        Solve(arr, i + 1, temp, ans, sum, count);
        ans -= arr[i];
        temp.pop_back();
    }
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

    vector<int> temp;

    int sum;
    cin >> sum;

    int ans = 0;
    int count = 0;
    Solve(arr, 0, temp, ans, sum, count);

    cout << "Possible Count : " << count << endl;
    return 0;
}