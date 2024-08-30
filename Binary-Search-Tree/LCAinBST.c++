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
Node *buildBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = buildBST(root->right, data);
    }
    else
    {
        root->left = buildBST(root->left, data);
    }

    return root;
}
void insert(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = buildBST(root, data);
        cin >> data;
    }
}
void Traversal(Node *root)
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
            break;
        }
    }
    return root;
}
int main()
{
    Node *root = NULL;
    insert(root);
    Traversal(root);

    int p, q;
    cin >> p >> q;
    Node *LCA = LCAinBST(root, p, q);
    cout << "LCA : " << LCA->data << endl;
    return 0;
}