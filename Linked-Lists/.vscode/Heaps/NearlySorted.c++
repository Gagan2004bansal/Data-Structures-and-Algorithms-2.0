// https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

// link for the question
// NEARLY SORTED

// Given an array of n elements, where each element is at most k away from its target position,
//  you need to sort the array optimally.
//  example : [6,5,3,2,8,10,9] , n = 7 , k = 3

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    vector<int> arr;
    cout << "Enter elements in array\n";
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    int k;
    cout << "Enter K : ";
    cin >> k;

    int size;
    size = n == k ? n : k + 1;

    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < size; i++)
    {
        pq.push(arr[i]);
    }

    vector<int> res;
    for (int i = k + 1; i < n; i++)
    {
        res.push_back(pq.top());
        pq.pop();
        pq.push(arr[i]);
    }

    while (!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }

    cout << endl;

    return 0;
}