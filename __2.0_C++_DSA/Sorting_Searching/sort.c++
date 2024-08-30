// Bubble Sort

// #include <iostream>
// #include <vector>
// using namespace std;
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

//     // Bubble Sort
//     for (int i = 0; i < n - 1; i++)
//     {
//         bool swapped = false;
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 swap(arr[j], arr[j + 1]);
//                 swapped = true;
//             }
//         }

//         if (swapped == false)
//         {
//             break;
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// Selection Sort
// #include <iostream>
// #include <vector>
// using namespace std;
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

//     // Selection Sort
//     int minIndex;
//     for (int i = 0; i < n - 1; i++)
//     {
//         minIndex = i;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[minIndex])
//             {
//                 minIndex = j;
//             }
//         }
//         swap(arr[i], arr[minIndex]);
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }

// Insertion Sort
#include <iostream>
#include <vector>
using namespace std;
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

    // Insertion Sort
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        int k = i - 1;
        for (; k >= 0; k--)
        {
            if (arr[k] > temp)
            {
                arr[k + 1] = arr[k];
            }
            else
            {
                break;
            }
        }
        arr[k + 1] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Quick Sort
// #include <iostream>
// #include <vector>
// using namespace std;
// int partion(vector<int> &arr, int s, int e)
// {
//     int pivot = arr[e];
//     int i = s - 1;
//     for (int j = s; j <= e; j++)
//     {
//         if (arr[j] < pivot)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[e]);
//     return (i + 1);
// }
// void Quicksort(vector<int> &arr, int s, int e)
// {
//     if (s < e)
//     {
//         int p = partion(arr, s, e);

//         Quicksort(arr, s, p - 1);
//         Quicksort(arr, p + 1, e);
//     }
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

//     int low = 0;
//     int high = n - 1;
//     Quicksort(arr, low, high);

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

// Merge Sort
// #include <iostream>
// #include <vector>
// using namespace std;
// void MergeArr(vector<int> &arr, int s, int e)
// {
//     int mid = s + (e - s) / 2;
//     int len1 = mid - s + 1;
//     int len2 = e - mid;
//     int *arr1 = new int[len1];
//     int *arr2 = new int[len2];
//     int mainArrayIndex = s;

//     for (int i = 0; i < len1; i++)
//     {
//         arr1[i] = arr[mainArrayIndex++];
//     }
//     mainArrayIndex = mid + 1;
//     for (int i = 0; i < len2; i++)
//     {
//         arr2[i] = arr[mainArrayIndex++];
//     }

//     mainArrayIndex = s;
//     int i = 0, j = 0;
//     while (i < len1 && j < len2)
//     {
//         if (arr1[i] < arr2[j])
//         {
//             arr[mainArrayIndex++] = arr1[i++];
//         }
//         else if (arr2[j] < arr1[i])
//         {
//             arr[mainArrayIndex++] = arr2[j++];
//         }
//         else
//         {
//             arr[mainArrayIndex++] = arr1[i++];
//         }
//     }

//     while (i < len1)
//     {
//         arr[mainArrayIndex++] = arr1[i++];
//     }
//     while (j < len2)
//     {
//         arr[mainArrayIndex++] = arr2[j++];
//     }

//     delete[] arr1;
//     delete[] arr2;
// }
// void Mergesort(vector<int> &arr, int s, int e)
// {
//     if (s >= e)
//     {
//         return;
//     }

//     int mid = s + (e - s) / 2;

//     Mergesort(arr, s, mid);
//     Mergesort(arr, mid + 1, e);

//     MergeArr(arr, s, e);
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

//     int s = 0;
//     int e = n - 1;
//     Mergesort(arr, s, e);

//     for (int i = 0; i < n; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

//  Linear Search
// #include <iostream>
// #include <vector>
// using namespace std;
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

//     int key;
//     cin >> key;

//     for (int i = 0; i < n; i++)
//     {
//         if (key == arr[i])
//         {
//             cout << "Found!" << endl;
//         }
//     }

//     return 0;
// }

// Binary Search
// #include <iostream>
// #include <vector>
// using namespace std;
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

//     int key;
//     cin >> key;

//     int s = 0, e = n, mid = s + (e - s) / 2;
//     while (s < e)
//     {
//         if (arr[mid] == key)
//         {
//             cout << "Found!" << endl;
//             break;
//         }
//         else if (arr[mid] < key)
//         {
//             s = mid + 1;
//         }
//         else
//         {
//             e = mid - 1;
//         }
//         mid = s + (e - s) / 2;
//     }

//     return 0;
// }