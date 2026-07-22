#include <iostream>
#include <vector>
#include <map>

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

void InsertTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void Display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isCircularLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    Node *temp = head->next;
    while (temp != NULL)
    {
        if (head == temp)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool DetectLoop1(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    map<Node *, int> mapp;
    Node *temp = head;

    while (temp != NULL)
    {
        if (mapp.find(temp) == mapp.end())
        {
            mapp[temp]++;
        }
        else
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

Node *DetectLoop2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast)
        {
            return slow;
        }
    }

    return NULL;
}

Node *StartingNode(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *intersection = DetectLoop2(head);
    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void RemoveLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    Node *StartNode = StartingNode(head);
    Node *temp = StartNode;

    while (temp->next != StartNode)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}

Node *IterativeReverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *forw = head;

    while (curr != NULL)
    {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }

    return prev;
}

Node *RecursiveReverse(Node *head)
{
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* revHead = RecursiveReverse(head -> next);

    head -> next -> next = head;

    head -> next = NULL;

    return revHead;
}

Node* ReverseInK(Node* head, int k){

    if(head == NULL || head -> next == NULL){
        return head;
    }

    int count = 0;
    Node* prev = NULL;
    Node* curr = head;
    Node* forw = head;
    while(count < k && curr != NULL){
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
        count++;
    }

    if(forw != NULL){
        head -> next = ReverseInK(forw, k);
    }

    return prev;

}

Node* RemovingDuplicate(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* temp = head;
    while(temp != NULL && temp -> next != NULL){
        if(temp -> data == temp -> next -> data){
            Node* nextTonext = temp -> next -> next;
            Node* toDelete = temp -> next;
            temp -> next -> next = NULL;
            delete toDelete;
            temp -> next = nextTonext;
        }
        else{
            temp = temp -> next;
        }
    }
    return head;
}

Node* sortOs1s2s(Node* head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;
    while(curr != NULL){
        if(curr -> data == 0){
            InsertTail(zeroHead, zeroTail, 0);
        }
        else if(curr -> data == 1){
            InsertTail(oneHead, oneTail, 1);
        }
        else{
            InsertTail(twoHead, twoTail, 2);
        }

        curr = curr -> next;
    }

    if(oneHead -> next != NULL){
        zeroTail -> next = oneHead -> next;
    }
    else{
        zeroTail -> next = twoHead -> next;
    }

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    head = zeroHead -> next;

    delete oneHead;
    delete twoHead;
    delete zeroHead;

    return head;
}

int main()
{

    // Linked Lists
    Node *head = NULL;
    Node *tail = head;

    int data = 0;
    while (data != -1)
    {
        cin >> data;
        if (data == -1)
        {
            break;
        }
        InsertTail(head, tail, data);
    }

    // Displaying the content of LL
    // Display(head);

    // Checking the Linked List is Circular
    // tail -> next = head;
    // cout << isCircularLL(head) << endl;

    // Checking is there any loop in LL
    // Type 1
    // tail -> next = head -> next -> next -> next;
    // cout << DetectLoop1(head) << endl;

    // Type 2
    // Node* LoopNode = DetectLoop2(head);
    // if(LoopNode == NULL){
    //     cout << "false" << endl;
    // }
    // else{
    //     cout << "True" << endl;
    // }

    // Finding Starting Node of L
    // Node* StartNode = StartingNode(head);
    // if(StartNode == NULL){
    //     cout << "false" << endl;
    // }
    // else{
    //     cout << StartNode -> data << endl;
    // }

    // Now Removing the Loop
    // RemoveLoop(head);
    // Display(head);

    // Reverse the Linked List
    // Type - 1
    // Node *type1 = IterativeReverse(head);
    // Display(type1);
    // Type - 2
    // Node* type2 = RecursiveReverse(head);
    // Display(type2);

    // int k;
    // cout << "Enter the K : ";
    // cin >> k;

    // // Reversing the LL into K-groups 
    // Node* kReverse = ReverseInK(head, k);
    // Display(kReverse);

    // Node* freshLL = RemovingDuplicate(head);
    // Display(freshLL);

    Node* sort012s = sortOs1s2s(head);
    Display(sort012s);

    return 0;
}