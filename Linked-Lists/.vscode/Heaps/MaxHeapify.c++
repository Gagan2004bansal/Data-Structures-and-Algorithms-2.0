// #include <iostream>
// using namespace std;
// void HeapifyArray(int *arr, int n, int i)
// {
//     int largest = i;
//     int left = 2 * i;
//     int right = 2 * i + 1;

//     if (left <= n && arr[largest] < arr[left])
//     {
//         largest = left;
//     }

//     if (right <= n && arr[largest] < arr[right])
//     {
//         largest = right;
//     }

//     if (largest != i)
//     {
//         swap(arr[largest], arr[i]);
//         HeapifyArray(arr, n, largest);
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n + 1];
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> arr[i];
//     }

//     for (int i = n / 2; i > 0; i--)
//     {
//         HeapifyArray(arr, n, i);
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// Heapify in 1-Based Indexing
// Does not include leaf node
#include <iostream>
#include <vector>
using namespace std;
void Heapify(vector<int> &arr, int n, int i)
{

    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        Heapify(arr, n, largest);
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

    // Heapify the array
    for (int i = n / 2; i > 0; i--)
    {
        Heapify(arr, n, i);
    }

    // Printing the array
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Heapify the array in max heap
// does not include leaf node
// #include <iostream>
// #include <vector>
// using namespace std;
// void Heapify(vector<int> &arr, int n, int i)
// {

//     int largest = i;
//     int left = 2 * i + 1;
//     int right = 2 * i + 2;

//     if (left < n && arr[largest] < arr[left])
//     {
//         largest = left;
//     }

//     if (right < n && arr[largest] < arr[right])
//     {
//         largest = right;
//     }

//     if (largest != i)
//     {
//         swap(arr[largest], arr[i]);
//         Heapify(arr, n, largest);
//     }
// }
// int main()
// {
//     int n;
//     cout << "Enter Size : ";
//     cin >> n;

//     vector<int> arr;
//     for (int i = 0; i < n; i++)
//     {
//         int a;
//         cin >> a;
//         arr.push_back(a);
//     }

//     // Heapify the array
//     for (int i = n / 2 - 1; i >= 0; i--)
//     {
//         Heapify(arr, n, i);
//     }

//     // printing the array
//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }