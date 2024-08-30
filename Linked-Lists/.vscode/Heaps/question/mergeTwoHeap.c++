// Merge 2 Heap
#include <iostream>
#include <vector>
using namespace std;
void Heapify(vector<int> &array, int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && array[largest] < array[left])
    {
        largest = left;
    }
    if (right < n && array[largest] < array[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(array[largest], array[i]);
        Heapify(array, n, largest);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int m;
    cin >> m;
    int brr[n];
    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
    }

    vector<int> array;
    array.push_back(-1);
    for (auto i : arr)
    {
        array.push_back(i);
    }
    for (auto j : brr)
    {
        array.push_back(j);
    }

    int size = array.size();
    for (int i = size / 2; i > 0; i--)
    {
        Heapify(array, size, i);
    }

    for (int i = 1; i < size - 1; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}