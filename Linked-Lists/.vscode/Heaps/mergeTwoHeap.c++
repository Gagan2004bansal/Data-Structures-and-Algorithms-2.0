#include <iostream>
#include <vector>
using namespace std;
void Heapify(vector<int> &arr, int n, int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right < n && arr[largest] < arr[right])
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
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int input1;
        cin >> input1;
        a.push_back(input1);
    }

    int m;
    cin >> m;
    vector<int> b;
    for (int i = 0; i < m; i++)
    {
        int input2;
        cin >> input2;
        b.push_back(input2);
    }

    vector<int> arr;
    for (auto i : a)
    {
        arr.push_back(i);
    }
    for (auto j : b)
    {
        arr.push_back(j);
    }

    int n1 = arr.size();
    for (int i = n1 / 2 - 1; i >= 0; i--)
    {
        Heapify(arr, n1, i);
    }

    for (int i = 0; i < n1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
