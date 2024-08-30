// Implementing Min Heap with 1-based Indexoing
#include <iostream>
#include <vector>
using namespace std;
class Heap
{
public:
    vector<int> arr;
    int size;

    Heap()
    {
        arr.push_back(0);
        this->size = 0;
    }

    void insertAtHeap(int data)
    {
        size++;
        int index = size;
        arr.push_back(data);

        while (index > 1 && arr[index] < arr[index / 2])
        {
            swap(arr[index], arr[index / 2]);
            index /= 2;
        }
    }
    void DeleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing Can be deleted as heap is empty !" << endl;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] > arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] > arr[rightIndex])
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
    void Display()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Heap h1;
    h1.insertAtHeap(13);
    h1.insertAtHeap(16);
    h1.insertAtHeap(31);
    h1.insertAtHeap(41);
    h1.insertAtHeap(51);
    h1.insertAtHeap(100);

    h1.Display();

    h1.DeleteFromHeap();

    h1.Display();

    return 0;
}