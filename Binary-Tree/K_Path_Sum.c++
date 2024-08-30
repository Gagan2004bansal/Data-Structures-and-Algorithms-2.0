#include <iostream>
#include <queue>
#include <vector>
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
void BuildFromLevelOrder(node *&root)
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
void Solve(node *root, int &count, int k, vector<int> path)
{
    if (root == NULL)
    {
        return;
    }

    path.push_back(root->data);

    Solve(root->left, count, k, path);
    Solve(root->right, count, k, path);

    int sum = 0;
    int size = path.size();

    for (int i = size - 1; i >= 0; i--)
    {
        sum = sum + path[i];
        if (sum == k)
        {
            count++;
        }
    }

    path.pop_back();
}
void KpathSum(node *root, int &count, int k)
{
    vector<int> path;
    Solve(root, count, k, path);
}
int main()
{
    node *root = NULL;
    BuildFromLevelOrder(root);
    int count = 0;

    int k;
    cout << endl
         << "Enter K sum : ";
    cin >> k;
    KpathSum(root, count, k);
    cout << count << endl;
    return 0;
}