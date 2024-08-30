#include <iostream>
#include <vector>
using namespace std;
void Display(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void InsertionSort(int n, vector<int> &arr)
{
    int k;
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        k = i - 1;
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

    Display(arr);
}
int partion(int s, int e, vector<int> &arr)
{
    int pivot = arr[e];
    int i = s - 1;
    for (int j = s; j <= e; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[e]);
    return (i + 1);
}
void Quicksort(int s, int e, vector<int> &arr)
{
    if (s < e)
    {
        int pos = partion(s, e, arr);

        Quicksort(s, pos - 1, arr);
        Quicksort(pos + 1, e, arr);
    }
}
void QuickSort(int n, vector<int> &arr)
{
    Quicksort(0, n - 1, arr);
    Display(arr);
}
void SelectionSort(int n, vector<int> &arr)
{
    int minIndex;
    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }

    Display(arr);
}
void MergeArr(int s, int e, vector<int> &arr)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[mainArrayIndex++];
    }
    mainArrayIndex = s;
    int i = 0, j = 0;
    while (i < len1 && j < len2)
    {
        if (arr1[i] < arr[j])
        {
            arr[mainArrayIndex++] = arr1[i++];
        }
        else if (arr1[i] > arr2[j])
        {
            arr[mainArrayIndex++] = arr2[j++];
        }
        else
        {
            arr[mainArrayIndex++] = arr1[i++];
        }
    }
    while (i < len1)
    {
        arr[mainArrayIndex++] = arr1[i++];
    }
    while (j < len2)
    {
        arr[mainArrayIndex++] = arr2[j++];
    }

    delete[] arr1;
    delete[] arr2;
}
void Mergesort(int s, int e, vector<int> &arr)
{
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    Mergesort(s, mid, arr);
    Mergesort(mid + 1, e, arr);

    MergeArr(s, e, arr);
}
void MergeSort(int n, vector<int> &arr)
{
    Mergesort(0, n - 1, arr);
    Display(arr);
}
void BubbleSort(int n, vector<int> &arr)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
    Display(arr);
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

    // InsertionSort(n, arr);
    // QuickSort(n, arr);
    // SelectionSort(n, arr);
    // MergeSort(n, arr);
    BubbleSort(n, arr);

    return 0;
}