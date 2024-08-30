#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void InsertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}
void Display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void IScircularLL(Node *head, Node *tail)
{
    if (head == NULL)
    {
        cout << "Circular LL" << endl;
        return;
    }

    Node *temp = head->next;
    tail->next = head;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        cout << "Circular LL" << endl;
        return;
    }
    cout << "Not a Circular LL" << endl;
}
Node *DetectLoop(Node *head, Node *tail)
{
    if (head == NULL)
    {
        return NULL;
    }

    map<Node *, bool> visited;
    Node *temp = head;

    tail->next = head->next->next;

    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return temp;
        }
        visited[temp] = true;
        temp = temp->next;
    }

    return NULL;
}
Node *Reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *forw = NULL;

    while (curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }

    return prev;
}
Node *middle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
Node *ReverseinKGroup(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *curr = head;
    Node *prev = NULL;
    Node *forw = NULL;

    int count = 0;
    while (count < k && curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
        count++;
    }

    if (forw != NULL)
    {
        head->next = ReverseinKGroup(forw, k);
    }

    return prev;
}
void RemoveDuplicate(Node *&head)
{
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            Node *next_next = temp->next->next;
            Node *toDelete = temp->next;
            delete toDelete;
            temp->next = next_next;
        }
        else
        {
            temp = temp->next;
        }
    }
}
void RemoveDuplicateFromUnsortedList(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    map<int, bool> visited;

    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        if (visited[curr->data])
        {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else
        {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
}
int main()
{
    Node *root = NULL;
    Node *head = root;
    Node *tail = root;

    int data;
    cin >> data;
    while (data != -1)
    {
        InsertAtTail(head, tail, data);
        cin >> data;
    }
    Display(head);
    // IScircularLL(head, tail);

    // Node *node = DetectLoop(head, tail);
    // cout << node->data << endl;

    // Node *temp = Reverse(head);
    // Display(temp);

    // cout << middle(head)->data << endl;

    // Node *temp = ReverseinKGroup(head, 3);
    // Display(temp);

    // RemoveDuplicate(head);
    // Display(head);

    RemoveDuplicateFromUnsortedList(head);
    Display(head);

    return 0;
}