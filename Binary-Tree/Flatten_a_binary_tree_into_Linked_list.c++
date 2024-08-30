// FLATTEN A BINARY TREE INTO LINKED LISTS --- BINARY TREE   --- MOST IMPORTANT DSA QUESTION
#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    // constructor
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void Traversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void buildFromLevelOrder(node *&root)
{
    int data;
    cout << "Enter data for root : ";
    cin >> data;

    if (data == -1)
        return;
    root = new node(data);

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter data for " << temp->data << " left node : ";
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter data for " << temp->data << " right node : ";
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
void flatten(node *root)
{
    node *current = root;
    while (current != NULL)
    {
        if (current->left)
        {
            node *pred = current->left;
            while (pred->right)
            {
                pred = pred->right;
            }

            pred->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }

        current = current->right;
    }
}
int main()
{
    node *root = NULL;
    buildFromLevelOrder(root);
    flatten(root);
    Traversal(root);
    return 0;
}