#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    // Creating Constructor
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
    cout << "Enter Data for root : ";
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
        cout << "Enter data for left of " << temp->data << " node : ";
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter data for right of " << temp->data << " node : ";
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
pair<bool, int> BalancedTree(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> leftAns = BalancedTree(root->left);
    pair<bool, int> rightAns = BalancedTree(root->right);

    bool first = leftAns.first;
    bool second = rightAns.first;
    bool diff = abs(leftAns.second - rightAns.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(leftAns.second, rightAns.second) + 1;
    if (first && second && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }

    return ans;
}
int main()
{
    node *root = NULL;

    // Creating of a Tree
    BuildTreeFromLevelOrder(root);

    // Balanaced Tree
    cout << "Answer : " << BalancedTree(root).first << endl;
    return 0;
}