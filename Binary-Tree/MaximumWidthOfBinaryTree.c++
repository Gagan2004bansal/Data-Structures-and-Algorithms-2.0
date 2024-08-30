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
void BuildFromLevelOrder(Node *&root)
{
    int data;
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
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}
int MaxWidth(Node *root)
{
    queue<pair<Node *, int> > q;
    q.push(make_pair(root, 0));
    int result = 0;

    while (!q.empty())
    {
        int size = q.size();
        int left, right;
        int level = q.front().second;
        for (int i = 0; i < size; i++)
        {
            int currValue = q.front().second - level;
            Node *temp = q.front().first;
            q.pop();

            if (i == 0)
            {
                left = currValue;
            }
            if (i == size - 1)
            {
                right = currValue;
            }

            if (temp->left)
                q.push(make_pair(temp->left, currValue * 2 + 1));
            if (temp->right)
                q.push(make_pair(temp->right, currValue * 2 + 2));
        }

        result = max(result, right - left + 1);
    }

    return result;
}
int main()
{
    Node *root = NULL;
    BuildFromLevelOrder(root);
    cout << MaxWidth(root) << endl;
    return 0;
}