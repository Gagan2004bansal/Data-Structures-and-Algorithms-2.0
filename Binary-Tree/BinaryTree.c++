#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildTree(node *root) // DFS
{
    int data;
    cout << "Enter the data : ";
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Entering the data in left of Node : " << data << endl;
    root->left = buildTree(root->left);
    cout << "Entering the data in right of Node : " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
void levelOrderTrasversal(node *root)
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
void inOrderTrasversal(node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }
    inOrderTrasversal(root->left);
    cout << root->data << " ";
    inOrderTrasversal(root->right);
}
void preOrderTrasversal(node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTrasversal(root->left);
    preOrderTrasversal(root->right);
}
void postOrderTrasversal(node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }
    postOrderTrasversal(root->left);
    postOrderTrasversal(root->right);
    cout << root->data << " ";
}
void buildfromleveltrasversal(node *&root) // BFS
{
    queue<node *> q;
    cout << "Enter the data for root : ";
    int data;
    cin >> data;
    root = new node(data); // Here it is making main node known as root

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        // taking data for left node
        int leftdata;
        cout << "Enter data for " << temp->data << " left node ";
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        // taking data for right node
        int rightdata;
        cout << "Enter data for " << temp->data << " right node ";
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}
int main()
{
    node *root = NULL;
    // 3,9,20,null,null,15,7
    // buildTree Calling for making binary tree
    root = buildTree(root);
    // buildfromleveltrasversal(root);

    // levelOrdertransversal for printing of binary tree
    levelOrderTrasversal(root);

    // inOrderTrasversal(root);
    // preOrderTrasversal(root);
    // postOrderTrasversal(root);

    return 0;
}