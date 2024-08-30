#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *BuildTree(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (root->data < data)
    {
        root->right = BuildTree(root->right, data);
    }
    else
    {
        root->left = BuildTree(root->left, data);
    }
    return root;
}
void Inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
bool Search(Node *root, int data)
{
    Node *temp = root;
    while (temp)
    {
        if (temp->data == data)
        {
            return true;
        }
        if (temp->data < data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return false;
}
void MinMaxInBST(Node *root)
{
    Node *temp1 = root;
    Node *temp2 = root;
    int mini = INT_MAX, maxi = INT_MIN;
    while (temp1)
    {
        mini = min(mini, temp1->data);
        temp1 = temp1->left;
    }
    while (temp2)
    {
        maxi = max(maxi, temp2->data);
        temp2 = temp2->right;
    }
    cout << "Min : " << mini << " Max : " << maxi << endl;
}
Node *LCA(Node *root, int m, int n)
{
    while (root)
    {
        if (root->data < m && root->data < n)
        {
            root = root->right;
        }
        else if (root->data > m && root->data > n)
        {
            root = root->left;
        }
        else
        {
            break;
        }
    }
    return root;
}
int minInBST(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
Node *DeleteInBST(Node *root, int data)
{
    // Base Case
    if (root == NULL)
    {
        return root;
    }

    if (root->data == data)
    {
        // 0 Child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // 1 Child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 Child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minInBST(root->right);
            root->data = mini;
            root->right = DeleteInBST(root->right, mini);
            return root;
        }
    }
    else if (root->data < data)
    {
        root->right = DeleteInBST(root->right, data);
    }
    else if (root->data > data)
    {
        root->left = DeleteInBST(root->left, data);
    }
    return root;
}
void SuccessPredessor(Node *root, int key)
{
    int pred = -1;
    int succ = -1;
    Node *temp1 = root;
    Node *temp2 = root;
    while (temp1)
    {
        if (key >= temp1->data)
        {
            temp1 = temp1->right;
        }
        else
        {
            succ = temp1->data;
            temp1 = temp1->left;
        }
    }
    while (temp2)
    {
        if (key > temp2->data)
        {
            pred = temp2->data;
            temp2 = temp2->right;
        }
        else
        {
            temp2 = temp2->left;
        }
    }

    cout << "Pred : " << pred << endl;
    cout << "Succ : " << succ << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = BuildTree(root, arr[i]);
    }

    cout << "Inorder : ";
    Inorder(root);
    cout << endl;

    cout << "Search in BST : " << Search(root, 4) << endl;

    MinMaxInBST(root);

    int p1 = 1, p2 = 4;
    cout << "LCA of BST : " << LCA(root, p1, p2)->data << endl;

    int toDelete = 6;
    cout << toDelete << " is Deleted From BST " << endl;
    Node *rootD = DeleteInBST(root, toDelete);
    Inorder(rootD);
    cout << endl;

    int key = 4;
    SuccessPredessor(root, key);

    return 0;
}