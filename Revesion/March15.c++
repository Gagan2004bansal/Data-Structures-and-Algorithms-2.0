#include <iostream>
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
void InsertAthead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}
void InsertAttail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}
void InsertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 0)
    {
        InsertAthead(head, tail, data);
        return;
    }

    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (position == count)
    {
        InsertAttail(head, tail, data);
        return;
    }

    Node *newNode = new Node(data);
    temp = head;
    for (int i = 1; i < position; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return;
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
void DeleteNode(Node *&head, int position)
{
    if (position == 0)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int count = 0;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
bool IsCircular(Node *head)
{
    if (head == NULL)
    {
        return true;
    }
    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}
Node *getMid(Node *head)
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
int main()
{
    Node *root = NULL;
    Node *head = root;
    Node *tail = root;

    InsertAthead(head, tail, 1);
    InsertAthead(head, tail, 2);
    InsertAthead(head, tail, 3);
    InsertAthead(head, tail, 4);
    InsertAthead(head, tail, 5);
    InsertAttail(head, tail, 6);
    InsertAtPosition(head, tail, 7, 4);

    Display(head);
    Node *mid = getMid(head);
    cout << mid->data << endl;
    DeleteNode(head, 4);
    DeleteNode(head, 5);
    Display(head);
    cout << IsCircular(head) << endl;
    Node *mid1 = getMid(head);
    cout << mid1->data << endl;

    return 0;
}