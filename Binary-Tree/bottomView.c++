#include <iostream>
#include <queue>
#include <algorithm>
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
class I_O
{
public:
    void buildFromLevelOrder(node *&root)
    {
        int data;
        cout << "Enter data for the root : ";
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
    void levelOrderTraversal(node *root)
    {
        queue<node *> q;
        q.push(root);
        q.push(NULL);

        cout << "Level Order Traversal \n";
        while (!q.empty())
        {
            node *temp = q.front();
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
};
class Solution
{
public:
    vector<int> BottomView(node *root)
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

            topNode[hd] = frontNode->data;

            if (frontNode->left)
            {
                q.push(make_pair(frontNode->left, hd - 1));
            }

            if (frontNode->right)
            {
                q.push(make_pair(frontNode->right, hd + 1));
            }
        }
        cout << endl
             << "Bottom View \n";
        for (auto i : topNode)
        {
            ans.push_back(i.second);
        }

        return ans;
    }
};
int main()
{
    node *root = NULL;
    I_O obj1;
    obj1.buildFromLevelOrder(root);
    obj1.levelOrderTraversal(root);

    vector<int> res;
    Solution s1;
    res = s1.BottomView(root);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}