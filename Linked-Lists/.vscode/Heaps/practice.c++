// // #include <iostream>
// // using namespace std;
// // class Heap
// // {
// // public:
// //     int arr[100];
// //     int size;

// //     Heap()
// //     {
// //         this->size = 0;
// //     }
// //     void insertAtHeap(int data)
// //     {
// //         size = size + 1;
// //         int index = size;
// //         arr[index] = data;

// //         while (index > 1)
// //         {
// //             int parent = index / 2;
// //             if (arr[parent] < arr[index])
// //             {
// //                 swap(arr[index], arr[parent]);
// //             }
// //             else
// //             {
// //                 return;
// //             }
// //         }
// //     }
// //     void Display()
// //     {
// //         for (int i = 1; i <= size; i++)
// //         {
// //             cout << arr[i] << " ";
// //         }
// //         cout << endl;
// //     }
// //     void MaxELementinHeap()
// //     {
// //         cout << arr[1] << endl;
// //     }

// //     void DeleteFromHeap()
// //     {
// //         if (size == 0)
// //         {
// //             cout << "Nothing Can be Delete.." << endl;
// //             return;
// //         }

// //         arr[1] = arr[size];
// //         size--;

// //         int i = 1;
// //         while (i < size)
// //         {
// //             int leftIndex = 2 * i;
// //             int rightIndex = 2 * 1 + 1;
// //             if (leftIndex < size && arr[i] < arr[leftIndex])
// //             {
// //                 swap(arr[i], arr[leftIndex]);
// //                 i = leftIndex;
// //             }
// //             else if (rightIndex < size && arr[i] < arr[rightIndex])
// //             {
// //                 swap(arr[i], arr[rightIndex]);
// //                 i = rightIndex;
// //             }
// //             else
// //             {
// //                 return;
// //             }
// //         }
// //     }

// //     void CurrentHeapSize()
// //     {
// //         cout << size << endl;
// //     }
// // };
// // int main()
// // {
// //     Heap h1;

// //     h1.insertAtHeap(50);
// //     h1.insertAtHeap(55);
// //     h1.insertAtHeap(53);
// //     h1.insertAtHeap(52);
// //     h1.insertAtHeap(54);

// //     h1.Display();

// //     h1.DeleteFromHeap();
// //     h1.Display();

// //     h1.CurrentHeapSize();

// //     return 0;
// // }

// #include <iostream>
// using namespace std;
// class Heap
// {
// public:
//     int arr[100];
//     int size;

//     Heap()
//     {
//         this->size = 0;
//     }

//     void insertAtHeap(int data)
//     {
//         size = size + 1;
//         int index = size;
//         arr[index] = data;

//         while (index > 1)
//         {
//             int parent = index / 2;
//             if (arr[parent] < arr[index])
//             {
//                 swap(arr[parent], arr[index]);
//             }
//             else
//             {
//                 return;
//             }
//         }
//     }
//     void DeleteFromHeap()
//     {
//         if (size == 0)
//         {
//             cout << "Nothing Can be deleted as Heap is empty !" << endl;
//         }

//         arr[1] = arr[size];
//         size--;

//         int i = 1;
//         while (i < size)
//         {
//             int leftIndex = 2 * i;
//             int rightIndex = 2 * i + 1;

//             if (leftIndex < size && arr[i] < arr[leftIndex])
//             {
//                 swap(arr[i], arr[leftIndex]);
//             }
//             else if (rightIndex < size && arr[i] < arr[rightIndex])
//             {
//                 swap(arr[i], arr[rightIndex]);
//             }
//             else
//             {
//                 return;
//             }
//         }
//     }
//     void Display()
//     {
//         for (int i = 1; i <= size; i++)
//         {
//             cout << arr[i] << " ";
//         }
//         cout << endl;
//     }
// };
// int main()
// {
//     Heap h1;

//     h1.insertAtHeap(1);
//     h1.insertAtHeap(2);
//     h1.insertAtHeap(3);
//     h1.insertAtHeap(4);
//     h1.insertAtHeap(5);

//     h1.DeleteFromHeap();

//     h1.Display();
//     return 0;
// }

// // Difference Between 0-based indexing Heap and 1-based indexing Heap
// // Use 1-based indexing heap as it costs less than 0-based indexing Heap
// //                   root at 0       root at 1
// // Left child        index * 2 + 1     index * 2
// // Right child       index * 2 + 2     index * 2 + 1
// // Parent            (index-1)/2     index/2

// Lets Create Heap using STL
// #include <iostream>
// #include <queue>
// using namespace std;
// int main()
// {
//     int arr[] = {7, 10, 4, 3, 20, 15};

//     // creating priority queue
//     priority_queue<int> pq; // Max Heap
//     for (int i = 0; i < 5; i++)
//     {
//         pq.push(arr[i]);
//     }

//     cout << "Max element : " << pq.top() << endl;
//     cout << "Space : " << pq.empty() << endl;
//     pq.pop();
//     cout << "After Pop element : " << pq.top() << endl;

//     // creating min heap using stl
//     priority_queue<int, vector<int>, greater<int> > pq1;
//     for (int i = 0; i < 5; i++)
//     {
//         pq1.push(arr[i]);
//     }

//     cout << "Max element : " << pq1.top() << endl;
//     cout << "Space : " << pq1.empty() << endl;
//     pq1.pop();
//     cout << "After Pop element : " << pq1.top() << endl;

//     return 0;
// }

// Practice on 8 Feb 2024
// #include <iostream>
// using namespace std;
// class Heap
// {
// public:
//     int arr[100];
//     int size;

//     Heap()
//     {
//         this->size = 0;
//     }

//     void Insert(int data);
//     void Display();
//     void Deletion();
// };
// void Heap::Insert(int data)
// {
//     size = size + 1;
//     int index = size;
//     arr[index] = data;

//     while (index > 1)
//     {
//         int parent = index / 2;
//         if (arr[parent] < arr[index])
//         {
//             swap(arr[index], arr[parent]);
//             index = parent;
//         }
//         else
//         {
//             return;
//         }
//     }
// }
// void Heap::Display()
// {
//     for (int i = 1; i <= size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
// void Heap::Deletion()
// {
//     if (size == 0)
//     {
//         cout << "Heap is empty !" << endl;
//         return;
//     }

//     arr[1] = arr[size];
//     size--;

//     // ab heapify krna pdega
//     int i = 1;
//     while (i < size)
//     {
//         int left = 2 * i;
//         int right = 2 * i + 1;

//         if (left < size && arr[i] < arr[left])
//         {
//             swap(arr[i], arr[left]);
//         }
//         else if (right < size && arr[i] < arr[right])
//         {
//             swap(arr[i], arr[right]);
//         }
//         else
//         {
//             return;
//         }
//     }
// }
// int main()
// {
//     Heap h1;

//     h1.Insert(10);
//     h1.Insert(2);
//     h1.Insert(3);
//     h1.Insert(5);
//     h1.Insert(4);

//     h1.Display();

//     h1.Deletion();
//     h1.Display();

//     h1.Insert(15);
//     h1.Display();

//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// void Heapify(vector<int> &arr, int n, int i)
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
//         Heapify(arr, n, largest);
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> arr;
//     arr.push_back(-1);
//     for (int i = 0; i < n; i++)
//     {
//         int input;
//         cin >> input;
//         arr.push_back(input);
//     }

//     for (int i = n / 2; i > 0; i--)
//     {
//         Heapify(arr, n, i);
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         cout << arr[i] << " ";
//     }

//     cout << endl;

//     return 0;
// }

// Min Heapify
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
    cin >> n;

    vector<int> arr;
    arr.push_back(-1);
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
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