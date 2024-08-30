#include <iostream>
using namespace std;
void HeapifyArray(int *arr, int n, int i)
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
        HeapifyArray(arr, n, largest);
    }
}
void heapsort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        // swap
        swap(arr[size], arr[1]);
        size--;

        HeapifyArray(arr, size, 1);
    }
}
int main()
{
    int n;
    cout << "Enter size of array : " << endl;
    cin >> n;
    int arr[n + 1];
    cout << "Enter elements in array " << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = n / 2; i >= 0; i--)
    {
        HeapifyArray(arr, n, i);
    }

    cout << "Creating a Heap from Array \n";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapsort(arr, n);
    cout << "After Heap Sort \n";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}