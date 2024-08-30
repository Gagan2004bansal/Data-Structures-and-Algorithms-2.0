#include <iostream>
#include <vector>
using namespace std;
class Heap
{
public:
    int size;
    int arr[1000];

    Heap()
    {
        this->size = 0;
    }

    void insertData(int data);
    void print();
    void Max();
    void Deletion();
    bool isEmpty();
};
void Heap::insertData(int data)
{
    size++;
    arr[size] = data;
    int index = size;
    while (index > 1)
    {
        int parent = index / 2;
        if (arr[parent] < arr[index])
        {
            swap(arr[index], arr[parent]);
            index = parent;
        }
        else
        {
            return;
        }
    }
}
void Heap::print()
{
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Heap::Max()
{
    cout << arr[1] << endl;
}
void Heap::Deletion()
{
    if (size == 0)
    {
        cout << "Heap is empty!" << endl;
    }

    arr[1] = arr[size];
    size--;

    int i = 1;
    while (i < size)
    {
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;

        if (leftIndex < size && arr[i] < arr[leftIndex])
        {
            swap(arr[i], arr[leftIndex]);
            i = leftIndex;
        }
        else if (rightIndex < size && arr[i] < arr[rightIndex])
        {
            swap(arr[i], arr[rightIndex]);
            i = rightIndex;
        }
        else
        {
            return;
        }
    }
}
bool Heap::isEmpty()
{
    if (size != 0)
    {
        return false;
    }
    return true;
}
void MaxHeapify(vector<int> &arr, int n, int i)
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
        MaxHeapify(arr, n, largest);
    }
}
void MinHeapify(vector<int> &array, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[smallest] > array[left])
    {
        smallest = left;
    }

    if (right < n && array[smallest] > array[right])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(array[smallest], array[i]);
        MinHeapify(array, n, smallest);
    }
}
int main()
{
    Heap h1;
    h1.insertData(3);
    h1.insertData(4);
    h1.insertData(9);
    h1.insertData(5);
    h1.insertData(2);

    h1.print();
    h1.Max();
    h1.Deletion();
    h1.print();
    cout << h1.isEmpty() << endl;

    // Lets Create a Max Heap from array !!
    int n;
    cout << "Enter Size of array : " << endl;
    cin >> n;

    vector<int> arr;
    cout << "Enter elements in array \n";
    arr.push_back(-1);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    // to convert array into heap then this algorithm is known as Heapify
    // for 1-based indexing
    for (int i = n / 2; i > 0; i--)
    {
        MaxHeapify(arr, n, i);
    }

    // printing of heap
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Lets create a Min Heap from array
    int m;
    cout << "Enter size of array : " << endl;
    cin >> m;

    vector<int> array;
    cout << "Enter element in array \n";
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        array.push_back(b);
    }

    // lets convert array into min heap with 0-based indexing with heapify algorithm
    // for (int i = n / 2 - 1; i >= 0; i--)
    // {
    //     MinHeapify(array, n, i);
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << array[i] << " ";
    // }
    // cout << endl;

    return 0;
}