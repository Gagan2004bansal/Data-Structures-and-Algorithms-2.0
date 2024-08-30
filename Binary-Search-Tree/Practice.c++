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
Node *InsertDatainBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = InsertDatainBST(root->right, data);
        return root;
    }
    else
    {
        root->left = InsertDatainBST(root->left, data);
        return root;
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
void InsertData(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = InsertDatainBST(root, data);
        cin >> data;
    }
}
void InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
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

bool Searching(Node *root, int key)
{
    Node *temp = root;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }

        if (key < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    return false;
}

void MinElement(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    cout << temp->data << " " << endl;
}

void MaxElement(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    cout << temp->data << " " << endl;
}

Node *MinElementBST(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}

Node *DeleteFromBST(Node *root, int value)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == value)
    {
        // case 1 : O Child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // case 2 : 1 Child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // case 3 : 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = MinElementBST(root->right)->data;
            root->data = mini;
            root->right = DeleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (value > root->data)
    {
        root->right = DeleteFromBST(root->right, value);
        return root;
    }
    else
    {
        root->left = DeleteFromBST(root->left, value);
        return root;
    }
}

void InorderPredessorSuccessor(Node *root, int key)
{
    Node *temp1 = root;
    Node *temp2 = root;

    int Pre = -1;
    int succ = -1;

    // Successor
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
            Pre = temp2->data;
            temp2 = temp2->right;
        }
        else
        {
            temp2 = temp2->left;
        }
    }

    cout << "Pred : " << Pre << endl;
    cout << "Succ : " << succ << endl;
}

Node *LCAinBST(Node *root, int p, int q)
{
    while (root != NULL)
    {
        if (root->data < p && root->data < q)
        {
            root = root->right;
        }
        else if (root->data > p && root->data > q)
        {
            root = root->left;
        }
        else
        {
            return root;
        }
    }

    return root;
}

int main()
{
    Node *root = NULL;
    InsertData(root);
    cout << "Level Order Traversal of Binary Search Tree " << endl;
    LevelOrderTraversal(root);

    cout << "Inorder Traversal : " << endl;
    InOrder(root);
    cout << endl;

    cout << "PreOrder Traversal : " << endl;
    PreOrder(root);
    cout << endl;

    cout << "PostOrder Traversal : " << endl;
    PostOrder(root);
    cout << endl;

    int key;
    cout << "Enter the key you want to search : " << endl;
    cin >> key;

    bool ans = Searching(root, key);
    if (ans)
    {
        cout << "Found!" << endl;
    }
    else
    {
        cout << "Not Found!" << endl;
    }

    cout << "Minimum Element is ";
    MinElement(root);

    cout << "Maximum Element is ";
    MaxElement(root);

    DeleteFromBST(root, 4);

    LevelOrderTraversal(root);

    InorderPredessorSuccessor(root, 8);

    cout << "LCA of p and q in BST : " << LCAinBST(root, 1, 6)->data << endl;

    return 0;
}