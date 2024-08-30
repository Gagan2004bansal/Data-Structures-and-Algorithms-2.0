// Morris Traversal -- PREORDER TREE TRAVERSAL  --- BINARY TREE   --- MOST IMPORTANT DSA QUESTION
// Morris Traversal can traverse the tree without using stack and recursion
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
void morrisTraversal(node *root)
{
    while (root)
    {
        if (root->left == NULL)
        {
            cout << root->data << " ";
            root = root->right;
        }
        else
        {
            node *current = root->left;
            while (current->right && current->right != root)
            {
                current = current->right;
            }

            if (current->right == root)
            {
                current->right = NULL;
                root = root->right;
            }
            else
            {
                cout << root->data << " ";
                current->right = root;
                root = root->left;
            }
        }
    }
}
int main()
{
    node *root = NULL;
    buildFromLevelOrder(root);
    morrisTraversal(root);
    return 0;
}