#include <iostream>
#include <vector>

using namespace std;

// MAX HEAP IMPLEMENTATION
class Heap {
    private:
    vector<int> heap;

    public:
    void push(int val) {
        heap.push_back(val);
        int index = heap.size() - 1;

        while(index > 0) {
            int parent = (index - 1) / 2;
            if(heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            }
            else {
                break;
            }
        }
    } 

    void pop() {

        if(heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();

        int index = 0;
        int n = heap.size()-1;

        while(true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if(left <= n && heap[left] > heap[largest]) {
                largest = left;
            }
            if(right <= n && heap[right] > heap[largest]) {
                largest = right;
            }

            if(largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else {
                break;
            }
        }
    }

    int top() {
        return heap[0];
    }

    int empty() {
        return heap.empty();
    }
};

int main() {

    Heap h;

    h.push(10);
    h.push(50);
    h.push(30);
    h.push(20);

    cout << h.top() << endl;

    h.pop();


    return 0;
}