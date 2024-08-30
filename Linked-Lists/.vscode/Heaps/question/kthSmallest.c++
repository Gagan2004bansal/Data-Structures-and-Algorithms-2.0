// Find Kth smallest number in an array without using sort
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

    priority_queue<int> pq;

    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    int s = 0, e = n - 1;

    for (int i = k; i <= e; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    cout << pq.top() << endl;

    return 0;
}