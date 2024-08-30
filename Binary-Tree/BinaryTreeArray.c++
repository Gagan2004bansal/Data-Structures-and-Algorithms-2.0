#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void buildFromLevelTraversal(Node *&root, vector<int> nums)
{
    queue<Node *> q;
    if (nums.size() <= 0)
    {
        return;
    }

    root = new Node(nums[0]);
    q.push(root);
    int i = 1;

    while (i < nums.size())
    {
        Node *temp = q.front();
        q.pop();

        if (i < nums.size())
        {
            temp->left = new Node(nums[i++]);
            q.push(temp->left);
        }
        if (i < nums.size())
        {
            temp->right = new Node(nums[i++]);
            q.push(temp->right);
        }
    }
}
void levelOrdertransversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
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
void inOrderTrasversal(Node *root)
{
    // Base Case
    if (root == nullptr)
    {
        return;
    }
    inOrderTrasversal(root->left);
    cout << root->data << " ";
    inOrderTrasversal(root->right);
}
void preOrderTrasversal(Node *root)
{
    // Base Case
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preOrderTrasversal(root->left);
    preOrderTrasversal(root->right);
}
void postOrderTrasversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postOrderTrasversal(root->left);
    postOrderTrasversal(root->right);
    cout << root->data << " ";
}
int main()
{
    Node *root = nullptr;
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        nums.push_back(input);
    }
    // Build Tree From Array
    buildFromLevelTraversal(root, nums);

    // Printing of Tree
    levelOrdertransversal(root);

    // inorder traversal LNR
    inOrderTrasversal(root);

    // preorder traversal NLR
    cout << endl;
    preOrderTrasversal(root);

    // postorder traversal LRN
    cout << endl;
    postOrderTrasversal(root);
    return 0;
}