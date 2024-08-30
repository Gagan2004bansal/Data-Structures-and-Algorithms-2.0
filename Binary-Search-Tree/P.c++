#include <iostream>
#include <queue>
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
Node *buildTree(Node *root, int data)
{
    if (root == NULL)
    {
        Node *temp = new Node(data);
        return temp;
    }

    if (data <= root->data)
    {
        root->left = buildTree(root->left, data);
    }
    else
    {
        root->right = buildTree(root->right, data);
    }

    return root;
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
bool SearchInBST(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == data)
    {
        return true;
    }

    if (root->data < data)
    {
        return SearchInBST(root->right, data);
    }
    else
    {
        return SearchInBST(root->left, data);
    }
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
void PreOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void PostOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}
void InsertData(Node *&root)
{
    int data;
    cin >> data;
    if (data == -1)
    {
        return;
    }

    while (data != -1)
    {
        root = buildTree(root, data);
        cin >> data;
    }
}
Node *MinInBST(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *DeleteFromBST(Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == data)
    {
        // Case 1
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // Case 2
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
        // case 3
        if (root->left != NULL && root->right != NULL)
        {
            int data = MinInBST(root->right)->data;
            root->data = data;
            root->right = DeleteFromBST(root->right, data);
            return root;
        }
    }
    else if (root->data < data)
    {
        root->right = DeleteFromBST(root->right, data);
    }
    else
    {
        root->left = DeleteFromBST(root->left, data);
    }
    return root;
}
int main()
{
    Node *root = NULL;
    InsertData(root);
    LevelOrderTraversal(root);
    // PreOrder(root);
    // cout << endl;
    // PostOrder(root);
    // cout << endl;
    // Inorder(root);
    // cout << endl;

    cout << SearchInBST(root, 2) << endl;
    root = DeleteFromBST(root, 40);
    LevelOrderTraversal(root);
    return 0;
}