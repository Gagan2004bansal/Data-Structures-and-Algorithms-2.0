// Right View and Left View Of Binary Tree
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    // Constructor
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
void BuildTreeFromLevelOrder(node *&root)
{
    int data;
    cout << "Enter data for root : ";
    cin >> data;

    if (data == -1)
    {
        return;
    }

    root = new node(data);
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter data for " << temp->data << " left Node : ";
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter data for " << temp->data << " right Node : ";
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
void LeftSolve(node *root, vector<int> &LeftAns, int level1)
{
    if (root == NULL)
    {
        return;
    }

    if (level1 == LeftAns.size())
    {
        LeftAns.push_back(root->data);
    }

    LeftSolve(root->left, LeftAns, level1 + 1);
    LeftSolve(root->right, LeftAns, level1 + 1);
}
void RightSolve(node *root, vector<int> &RightAns, int level2)
{
    if (root == NULL)
    {
        return;
    }
    if (level2 == RightAns.size())
    {
        RightAns.push_back(root->data);
    }

    RightSolve(root->right, RightAns, level2 + 1);
    RightSolve(root->left, RightAns, level2 + 1);
}
void Solution(node *root)
{
    vector<int> LeftAns;
    vector<int> RightAns;
    if (root == NULL)
    {
        cout << "Empty Root!" << endl;
        return;
    }

    int level1 = 0, level2 = 0;
    LeftSolve(root, LeftAns, level1);
    RightSolve(root, RightAns, level2);

    cout << "Left View " << endl;
    for (auto i : LeftAns)
    {
        cout << i << " ";
    }
    cout << endl
         << "Right View " << endl;
    for (auto j : RightAns)
    {
        cout << j << " ";
    }
    cout << endl;
}
int main()
{
    node *root = NULL;
    BuildTreeFromLevelOrder(root);

    Solution(root);
    return 0;
}