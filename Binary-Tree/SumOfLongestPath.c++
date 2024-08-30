#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

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
void FastCheck(node *root, int sum, int &maxSum, int len, int &maxLen)
{
    // Base Case
    if (root == NULL)
    {
        if (len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum = sum + root->data;

    FastCheck(root->left, sum, maxSum, len + 1, maxLen);
    FastCheck(root->right, sum, maxSum, len + 1, maxLen);
}
int Solution(node *root)
{
    int ans = 0;
    if (root == NULL)
    {
        return ans;
    }

    int sum = 0;
    int maxSum = INT_MIN;

    int len = 0;
    int maxLen = 0;

    FastCheck(root, sum, maxSum, len, maxLen);
    return maxSum;
}
int main()
{
    node *root = NULL;
    BuildTreeFromLevelOrder(root);
    cout << Solution(root) << endl;
    return 0;
}