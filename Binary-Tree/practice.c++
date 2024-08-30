#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    // Constructor
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildTree(node *root)
{
    int data;
    cout << "Enter data : ";
    cin >> data;

    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for left node of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for right node of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
void levelOrderTrasversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

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
void buildFromLevelTrasversal(node *&root)
{
    queue<node *> q;
    int data;
    cout << "Enter data for root : ";
    cin >> data;

    root = new node(data);
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
void preOrdereTrasversal(node *root)
{
    // Base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrdereTrasversal(root->left);
    preOrdereTrasversal(root->right);
}
void postOrderTrasversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrderTrasversal(root->left);
    postOrderTrasversal(root->right);
    cout << root->data << " ";
}
void InOrderTrasversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    InOrderTrasversal(root->left);
    cout << root->data << " ";
    InOrderTrasversal(root->right);
}
void ReverseOrderTrasversal(node *root)
{
    queue<node *> q;
    stack<node *> s;
    q.push(root);
    cout << endl;

    while (!q.empty())
    {
        root = q.front();
        q.pop();
        s.push(root);

        if (root->right)
        {
            q.push(root->right);
        }

        if (root->left)
        {
            q.push(root->left);
        }
    }

    while (!s.empty())
    {
        root = s.top();
        cout << root->data << " ";
        s.pop();
    }
}
void leafCountNodes(node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }

    leafCountNodes(root->left, count);
    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }

    leafCountNodes(root->right, count);
}
int height(node *root, int depth)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = height(root->left, depth);
    int right = height(root->right, depth);

    depth = max(left, right) + 1;

    return depth;
}
pair<int, int> DiameterFast(node *root)
{
    // Base Case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = DiameterFast(root->left);
    pair<int, int> right = DiameterFast(root->right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(opt1, max(opt2, opt3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}
void Diameter(node *root)
{
    cout << "Width or Diameter of Binary Tree is " << DiameterFast(root).first << endl;
}
// function of checking a binary tree is balaced or not
pair<bool, int> compareBinaryTree(node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<int, int> left = compareBinaryTree(root->left);
    pair<int, int> right = compareBinaryTree(root->right);

    bool first = left.first;
    bool second = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

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
void TopView(node *root)
{
    if (root == NULL)
    {
        return;
    }

    map<int, int> topNode;
    queue<pair<node *, int> > q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> front = q.front();
        q.pop();

        node *temp = front.first;
        int hd = front.second;

        if (topNode.find(hd) == topNode.end())
        {
            topNode[hd] = temp->data;
        }

        if (temp->left)
        {
            q.push(make_pair(temp->left, hd - 1));
        }

        if (temp->right)
        {
            q.push(make_pair(temp->right, hd + 1));
        }
    }

    cout << "Top View : ";
    for (auto it : topNode)
    {
        cout << it.second << " ";
    }
    cout << endl;
}
void BottomView(node *root)
{
    if (root == NULL)
    {
        return;
    }

    map<int, int> bottomNode;
    queue<pair<node *, int> > q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<node *, int> front = q.front();
        q.pop();

        node *temp = front.first;
        int hd = front.second;

        bottomNode[hd] = temp->data;

        if (temp->left)
        {
            q.push(make_pair(temp->left, hd - 1));
        }

        if (temp->right)
        {
            q.push(make_pair(temp->right, hd + 1));
        }
    }

    cout << "Bottom View : ";
    for (auto it : bottomNode)
    {
        cout << it.second << " ";
    }
    cout << endl;
}
void VerticalOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    map<int, map<int, vector<int> > > Nodes;
    queue<pair<node *, pair<int, int> > > q;
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        node *temp = q.front().first;
        int hd = q.front().second.first;
        int level = q.front().second.second;

        q.pop();

        Nodes[hd][level].push_back(temp->data);

        if (temp->left)
        {
            q.push(make_pair(temp->left, make_pair(hd - 1, level + 1)));
        }

        if (temp->right)
        {
            q.push(make_pair(temp->right, make_pair(hd + 1, level + 1)));
        }
    }

    cout << "Vertical Order Traversal \n";
    for (auto i : Nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                cout << k << " ";
            }
        }
    }
    cout << endl;
}
void LeftView(node *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (level == ans.size())
    {
        cout << root->data << " ";
        ans.push_back(root->data);
    }

    LeftView(root->left, level + 1, ans);
    LeftView(root->left, level + 1, ans);
}
void RightView(node *root, int level, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (level == ans.size())
    {
        cout << root->data << " ";
        ans.push_back(root->data);
    }

    RightView(root->right, level + 1, ans);
    RightView(root->right, level + 1, ans);
}
node *LCAofBianryTree(node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    node *LeftNode = LCAofBianryTree(root->left, n1, n2);
    node *RightNode = LCAofBianryTree(root->right, n1, n2);

    if (LeftNode != NULL && RightNode != NULL)
    {
        return root;
    }
    else if (LeftNode != NULL && RightNode == NULL)
    {
        return LeftNode;
    }
    else if (LeftNode == NULL && RightNode != NULL)
    {
        return RightNode;
    }
    else
    {
        return NULL;
    }
}
int main()
{
    node *root = NULL;
    // root = buildTree(root);              // <--- Creating Binary Tree
    buildFromLevelTrasversal(root); // <--- Creating Binary Tree
    levelOrderTrasversal(root);     // <--- Printing Binary Tree

    // preOrdereTrasversal(root);
    // InOrderTrasversal(root);
    // postOrderTrasversal(root);

    // ReverseOrderTrasversal(root);

    // int count = 0;
    // leafCountNodes(root, count);
    // cout << "Total leaf : " << count << endl;

    // int depth = 0;
    // int Heightdepth = height(root, depth);
    // cout << "Height or depth of binary tree is " << Heightdepth << endl;
    // Diameter(root);

    // bool res = compareBinaryTree(root).first;
    // if (res)
    // {
    //     cout << "Balaced Heigth Tree\n";
    // }
    // else
    // {
    //     cout << "Not a balanced Tree\n";
    // }

    // TopView(root);
    // BottomView(root);
    // VerticalOrderTraversal(root);
    // vector<int> ans;
    // LeftView(root, 0, ans);
    // RightView(root, 0, ans);

    node *ans1 = LCAofBianryTree(root, 4, 6);
    cout << ans1->data << " " << endl;
    return 0;
}