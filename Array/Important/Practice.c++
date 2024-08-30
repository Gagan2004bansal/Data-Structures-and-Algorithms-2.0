// Search in Rotated sorted array 1
// #include <iostream>
// #include <vector>
// using namespace std;
// int solve(int n, int k, vector<int> &arr)
// {
//     int s = 0;
//     int e = n - 1;
//     int mid = s + (e - s) / 2;
//     while (s <= e)
//     {
//         if (arr[mid] == k)
//         {
//             return mid;
//         }

//         if (arr[s] <= arr[mid])
//         {
//             if (k < arr[mid] && k >= arr[s])
//             {
//                 e = mid - 1;
//             }
//             else
//             {
//                 s = mid + 1;
//             }
//         }
//         else
//         {
//             if (k > arr[mid] && k <= arr[e])
//             {
//                 s = mid + 1;
//             }
//             else
//             {
//                 e = mid - 1;
//             }
//         }

//         mid = s + (e - s) / 2;
//     }

//     return -1;
// }
// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> arr;
//     for (int i = 0; i < n; i++)
//     {
//         int input;
//         cin >> input;
//         arr.push_back(input);
//     }

//     int k;
//     cin >> k;

//     cout << solve(n, k, arr) << endl;
//     return 0;
// }

// Search in a Rotated Array 2
// #include <iostream>
// #include <vector>
// using namespace std;
// bool solve(int n, int x, vector<int> &arr)
// {
//     int s = 0;
//     int e = n - 1;
//     int mid = s + (e - s) / 2;
//     while (s <= e)
//     {
//         if (arr[mid] == x)
//         {
//             return mid;
//         }
//         if (arr[s] == arr[mid] && arr[mid] == arr[e])
//         {
//             s++;
//             e--;
//         }
//         if (arr[s] <= arr[mid])
//         {
//             if (arr[s] <= x && x <= arr[mid])
//             {
//                 e = mid - 1;
//             }
//             else
//             {
//                 s = mid + 1;
//             }
//         }
//         else
//         {
//             if (arr[mid] <= x && x <= arr[e])
//             {
//                 s = mid + 1;
//             }
//             else
//             {
//                 e = mid - 1;
//             }
//         }
//         mid = s + (e - s) / 2;
//     }

//     return false;
// }
// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> arr;
//     for (int i = 0; i < n; i++)
//     {
//         int input;
//         cin >> input;
//         arr.push_back(input);
//     }

//     int k;
//     cin >> k;

//     cout << solve(n, k, arr) << endl;
//     return 0;
// }

// Find Peak Element in array
#include <iostream>
#include <vector>
using namespace std;
int solve(int n, vector<int> &arr)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] > arr[mid + 1])
        {
            e = mid;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    return s;
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

    cout << solve(n, arr) << endl;
    return 0;
}