#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <map>
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
class Solution
{
public:
    vector<int> TopView(node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        map<int, int> topNode;
        queue<pair<node *, int> > q;

        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            pair<node *, int> temp = q.front();
            q.pop();

            node *frontNode = temp.first;
            int hd = temp.second;

            if (topNode.find(hd) == topNode.end()) // hd denotes the vertical line on that particular node
            {
                topNode[hd] = frontNode->data;
            }

            if (frontNode->left)
            {
                q.push(make_pair(frontNode->left, hd - 1));
            }

            if (frontNode->right)
            {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }

        for (auto i : topNode)
        {
            ans.push_back(i.second);
        }
        return ans;
    }

    void Display(vector<int> res)
    {
        for (auto i : res)
        {
            cout << i << " ";
        }
        cout << endl;
    }
};
void buildOrderTraversal(node *&root)
{
    int data;
    cout << "Enter data for the root : ";
    cin >> data;
    queue<node *> q;

    root = new node(data);
    q.push(root);
    if (data == -1)
    {
        return;
    }

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
int main()
{
    node *root = NULL;
    buildOrderTraversal(root);
    Solution o1;
    vector<int> res;
    res = o1.TopView(root);
    o1.Display(res);
    return 0;
}