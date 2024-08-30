// Priority Queue  --> Min Heap and Max Heap [default]
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    cout << "Priority Queue \n";

    // Max Heap by defualt
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "Top element : " << pq.top() << endl;

    pq.pop();
    cout << "Top element : " << pq.top() << endl;

    cout << "Size : " << pq.size() << endl;
    cout << "Is Empty : " << pq.empty() << endl;

    // Min heap
    cout << "Min Heap Priority Queue" << endl;
    priority_queue<int, vector<int>, greater<int> > pq1;

    pq1.push(4);
    pq1.push(2);
    pq1.push(5);
    pq1.push(3);

    cout << "Top element : " << pq1.top() << endl;

    pq1.pop();
    cout << "Top element : " << pq1.top() << endl;

    cout << "Size : " << pq1.size() << endl;
    cout << "Is Empty : " << pq1.empty() << endl;

    return 0;
}