// // Median of a string ---> Data Stream
// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;
// int signum(int a, int b)
// {
//     if (a == b)
//     {
//         return 0;
//     }
//     else if (a > b)
//     {
//         return 1;
//     }
//     else
//     {
//         return -1;
//     }
// }
// void getMedian(int element, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int> > &minHeap, int &median)
// {
//     switch (signum(maxHeap.size(), minHeap.size()))
//     {
//     case 0:
//         if (element > median)
//         {
//             minHeap.push(element);
//             median = minHeap.top();
//         }
//         else
//         {
//             maxHeap.push(element);
//             median = maxHeap.top();
//         }
//         break;
//     case 1:
//         if (element > median)
//         {
//             minHeap.push(element);
//             median = (minHeap.top() + maxHeap.top()) / 2;
//         }
//         else
//         {
//             minHeap.push(maxHeap.top());
//             maxHeap.pop();
//             maxHeap.push(element);
//             median = (minHeap.top() + maxHeap.top()) / 2;
//         }
//         break;
//     case -1:
//         if (element > median)
//         {
//             maxHeap.push(minHeap.top());
//             minHeap.pop();
//             minHeap.push(element);
//             median = (minHeap.top() + maxHeap.top()) / 2;
//         }
//         else
//         {
//             maxHeap.push(element);
//             median = (minHeap.top() + maxHeap.top()) / 2;
//         }
//         break;
//     }
// }
// vector<int> findMedian(vector<int> arr, int n)
// {
//     vector<int> ans;
//     priority_queue<int> maxHeap;
//     priority_queue<int, vector<int>, greater<int> > minHeap;
//     int median = 0;

//     for (int i = 0; i < n; i++)
//     {
//         getMedian(arr[i], maxHeap, minHeap, median);
//         ans.push_back(median);
//     }

//     return ans;
// }
// int main()
// {
//     int n;
//     cout << "Enter Size of array : ";
//     cin >> n;
//     vector<int> arr;
//     cout << "Enter elements in array \n";
//     for (int i = 0; i < n; i++)
//     {
//         int input;
//         cin >> input;
//         arr.push_back(input);
//     }

//     vector<int> ans = findMedian(arr, n);

//     for (int i = 0; i < n; i++)
//     {
//         cout << ans[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int signum(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    else if (a > b)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
void getMedian(int element, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int> > &minHeap, int &median)
{
    switch (signum(maxHeap.size(), minHeap.size()))
    {
    case 0:
        if (element > median)
        {
            minHeap.push(element);
            median = minHeap.top();
        }
        else
        {
            maxHeap.push(element);
            median = maxHeap.top();
        }
        break;
    case 1:
        if (element > median)
        {
            minHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        else
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        break;
    case -1:
        if (element > median)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        else
        {
            maxHeap.push(element);
            median = (maxHeap.top() + minHeap.top()) / 2;
        }
        break;
    }
}
vector<int> Solution(vector<int> arr, int n)
{
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int median = 0;

    for (int i = 0; i < n; i++)
    {
        getMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }

    return ans;
}
int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> arr;
    cout << "Enter elements in array \n";
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    vector<int> res = Solution(arr, n);
    cout << "Median is : ";
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}