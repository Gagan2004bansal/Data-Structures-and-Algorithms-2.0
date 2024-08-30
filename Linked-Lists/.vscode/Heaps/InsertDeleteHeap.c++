#include <iostream>
using namespace std;
class heap
{
public:
    int size;
    int arr[100];

    heap()
    {
        int size = 0;
        arr[0] = -1;
    }

    void insert(int data)
    {
        size = size + 1;
        int index = size;
        arr[index] = data;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void MaxValue()
    {
        cout << arr[1] << endl;
    }

    void CurrentHeapSize()
    {
        cout << size << endl;
    }

    void DeleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing can be delete.." << endl;
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
};
int main()
{
    heap h;
    h.insert(5);
    h.insert(3);
    h.insert(4);
    h.insert(1);
    h.insert(2);
    h.print();

    h.MaxValue();

    h.DeleteFromHeap();
    h.print();
    h.CurrentHeapSize();
    return 0;
}