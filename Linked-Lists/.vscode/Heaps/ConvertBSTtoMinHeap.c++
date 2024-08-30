#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *CreatingNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = CreatingNode(root->right, data);
    }
    else
    {
        root->left = CreatingNode(root->left, data);
    }

    return root;
}
void InsertData(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = CreatingNode(root, data);
        cin >> data;
    }
}
void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
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
void inorder(Node *root, vector<int> &store)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, store);
    store.push_back(root->data);
    inorder(root->right, store);
}
void preorder(Node *root, vector<int> store, int &i)
{
    if (root == NULL)
    {
        return;
    }

    root->data = store[i++];
    preorder(root->left, store, i);
    preorder(root->right, store, i);
}

void preorderTra(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorderTra(root->left);
    preorderTra(root->right);
}

int main()
{
    Node *root = NULL;
    InsertData(root);
    LevelOrderTraversal(root);
    vector<int> store;

    int i = 0;
    inorder(root, store);
    preorder(root, store, i);

    preorderTra(root);

    return 0;
}