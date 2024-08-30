//  1 Based Indexing min heap Heapify
#include <iostream>
#include <vector>
using namespace std;
void Heapify(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[smallest] > arr[left])
    {
        smallest = left;
    }

    if (right <= n && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        Heapify(arr, n, smallest);
    }
}
int main()
{
    int n;
    cout << "Enter Size : ";
    cin >> n;

    vector<int> arr;
    arr.push_back(-1);
    cout << "Enter element in array \n";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    for (int i = n / 2; i > 0; i--)
    {
        Heapify(arr, n, i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// 0 Based Indexing min heap Heapify
// #include <iostream>
// #include <vector>
// using namespace std;
// void Heapify(vector<int> &arr, int n, int i)
// {
//     int smallest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     if (left < n && arr[smallest] > arr[left])
//     {
//         smallest = left;
//     }

//     if (right < n && arr[smallest] > arr[right])
//     {
//         smallest = right;
//     }

//     if (smallest != i)
//     {
//         swap(arr[smallest], arr[i]);
//         Heapify(arr, n, smallest);
//     }
// }
// int main()
// {
//     int n;
//     cout << "Enter Size : ";
//     cin >> n;

//     vector<int> arr;
//     cout << "Enter element in array \n";
//     for (int i = 0; i < n; i++)
//     {
//         int a;
//         cin >> a;
//         arr.push_back(a);
//     }

//     for (int i = n / 2 - 1; i >= 0; i--)
//     {
//         Heapify(arr, n, i);
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }