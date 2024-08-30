// Find Kth largest number in an array without using sort
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    priority_queue<int, vector<int>, greater<int> > pq;

    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i <= n - 1; i++)
    {
        if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    cout << k << " Max element : " << pq.top() << endl;

    return 0;
}