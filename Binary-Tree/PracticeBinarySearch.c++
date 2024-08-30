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
void BuildTreeFromLevelOrder(Node *&root)
{
    int data;
    cout << "Enter Data for root : ";
    cin >> data;

    if (data == -1)
    {
        return;
    }

    root = new Node(data);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter data for left of " << temp->data << " node : ";
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter data for right of " << temp->data << " node : ";
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
pair<int, int> DiameterofBinaryTree(Node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = DiameterofBinaryTree(root->left);
    pair<int, int> right = DiameterofBinaryTree(root->right);

    int leftAns = left.first;
    int rightAns = right.first;
    int opt3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(leftAns, max(rightAns, opt3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
int main()
{
    Node *root = NULL;

    BuildTreeFromLevelOrder(root);
    cout << "Width of Binary Tree : " << DiameterofBinaryTree(root).first << endl;
    return 0;
}