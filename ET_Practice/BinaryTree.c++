// #include <iostream>
// #include <vector>
// #include <queue>
// #include <map>
// #include <unordered_map>
// #include <set>
// #include <stack>
// #include <limits.h>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     Node(int data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// Node *BuildTreeFromDFS(Node *root, int &index, vector<int> &arr)
// {
//     if (index >= arr.size() || arr[index] == -1)
//     {
//         index++;
//         return NULL;
//     }

//     root = new Node(arr[index]);
//     index++;
//     root->left = BuildTreeFromDFS(root, index, arr);
//     root->right = BuildTreeFromDFS(root, index, arr);

//     return root;
// }
// void BuildTreeFromBFS(Node *&root, vector<int> &arr)
// {
//     if (arr.size() == 0)
//     {
//         return;
//     }

//     root = new Node(arr[0]);
//     int i = 1;
//     queue<Node *> q;
//     q.push(root);

//     while (i < arr.size())
//     {
//         Node *temp = q.front();
//         q.pop();

//         if (arr[i] != -1)
//         {
//             temp->left = new Node(arr[i]);
//             q.push(temp->left);
//         }
//         i++;

//         if (i < arr.size() && arr[i] != -1)
//         {
//             temp->right = new Node(arr[i]);
//             q.push(temp->right);
//         }
//         i++;
//     }
// }
// void LevelOrderTraversal(Node *root)
// {
//     queue<Node *> q;
//     q.push(root);
//     q.push(NULL);

//     while (!q.empty())
//     {
//         Node *temp = q.front();
//         q.pop();

//         if (temp == NULL)
//         {
//             cout << endl;
//             if (!q.empty())
//             {
//                 q.push(NULL);
//             }
//         }
//         else
//         {
//             cout << temp->data << " ";

//             if (temp->left)
//             {
//                 q.push(temp->left);
//             }

//             if (temp->right)
//             {
//                 q.push(temp->right);
//             }
//         }
//     }
// }
// void LeafNode(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     LeafNode(root->left);
//     if (root->left == NULL && root->right == NULL)
//     {
//         cout << root->data << " ";
//     }
//     LeafNode(root->right);
// }
// int HeightDepth(Node *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     int left = HeightDepth(root->left);
//     int right = HeightDepth(root->right);

//     int depth = max(left, right) + 1;
//     return depth;
// }
// pair<int, int> Diameter(Node *root)
// {
//     if (root == NULL)
//     {
//         pair<int, int> p = make_pair(0, 0);
//         return p;
//     }

//     pair<int, int> left = Diameter(root->left);
//     pair<int, int> right = Diameter(root->right);

//     int opt1 = left.first;
//     int opt2 = right.first;
//     int opt3 = left.second + right.second + 1;

//     pair<int, int> ans;
//     ans.first = max(opt1, max(opt2, opt3));
//     ans.second = max(left.second, right.second) + 1;
//     return ans;
// }
// void Spiral(Node *root)
// {
//     vector<int> result;
//     bool LeftToRight = true;

//     queue<Node *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         int size = q.size();
//         vector<int> temp(size);
//         for (int i = 0; i < size; i++)
//         {
//             Node *node = q.front();
//             q.pop();

//             int index = LeftToRight ? i : size - i - 1;
//             temp[index] = node->data;

//             if (node->left)
//             {
//                 q.push(node->left);
//             }

//             if (node->right)
//             {
//                 q.push(node->right);
//             }
//         }
//         LeftToRight = !LeftToRight;
//         for (int i = 0; i < size; i++)
//         {
//             result.push_back(temp[i]);
//         }
//     }
//     for (int i = 0; i < result.size(); i++)
//     {
//         cout << result[i] << " ";
//     }
// }
// Node *LCA(Node *root, int n1, int n2)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }

//     if (root->data == n1 || root->data == n2)
//     {
//         return root;
//     }

//     Node *left = LCA(root->left, n1, n2);
//     Node *right = LCA(root->right, n1, n2);

//     if (left && right)
//     {
//         return root;
//     }
//     else if (left == NULL && right)
//     {
//         return right;
//     }
//     else if (left && right == NULL)
//     {
//         return left;
//     }
//     else
//     {
//         return NULL;
//     }
// }
// int RootLeafSum(Node *root, string number = "")
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     number += to_string(root->data);
//     if (root->left == NULL && root->right == NULL)
//     {
//         return stoi(number);
//     }

//     int left = RootLeafSum(root->left, number);
//     int right = RootLeafSum(root->right, number);

//     return left + right;
// }
// void TopView(Node *root)
// {
//     queue<pair<Node *, int> > q;
//     q.push(make_pair(root, 0));
//     map<int, int> topNode;

//     while (!q.empty())
//     {
//         pair<Node *, int> front = q.front();
//         Node *temp = front.first;
//         int hl = front.second;
//         q.pop();

//         if (topNode.find(hl) == topNode.end())
//         {
//             topNode[hl] = temp->data;
//         }

//         if (temp->left)
//         {
//             q.push(make_pair(temp->left, hl - 1));
//         }

//         if (temp->right)
//         {
//             q.push(make_pair(temp->right, hl + 1));
//         }
//     }

//     for (auto i : topNode)
//     {
//         cout << i.second << " ";
//     }
//     cout << endl;
// }
// void BottomView(Node *root)
// {
//     map<int, int> bottomNode;
//     queue<pair<Node *, int> > q;
//     q.push(make_pair(root, 0));

//     while (!q.empty())
//     {
//         pair<Node *, int> front = q.front();
//         Node *temp = front.first;
//         int hl = front.second;
//         q.pop();

//         bottomNode[hl] = temp->data;

//         if (temp->left)
//         {
//             q.push(make_pair(temp->left, hl - 1));
//         }

//         if (temp->right)
//         {
//             q.push(make_pair(temp->right, hl + 1));
//         }
//     }

//     for (auto i : bottomNode)
//     {
//         cout << i.second << " ";
//     }
//     cout << endl;
// }
// void LeftView(Node *root, vector<int> &Leftarr, int level)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     if (level == Leftarr.size())
//     {
//         Leftarr.push_back(root->data);
//     }

//     LeftView(root->left, Leftarr, level + 1);
//     LeftView(root->right, Leftarr, level + 1);
// }
// void RightView(Node *root, vector<int> &Rightarr, int level)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     if (level == Rightarr.size())
//     {
//         Rightarr.push_back(root->data);
//     }

//     RightView(root->right, Rightarr, level + 1);
//     RightView(root->left, Rightarr, level + 1);
// }
// void BoundaryView(Node *root)
// {
//     vector<int> ans;
//     ans.push_back(root->data);
//     // Left View
//     // Left Leaf Node
//     // Right Leaf Node
//     // Right View

//     for (auto i : ans)
//     {
//         cout << i << " ";
//     }
// }
// void Inorder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     Inorder(root->left);
//     cout << root->data << " ";
//     Inorder(root->right);
// }
// void Preorder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     cout << root->data << " ";
//     Preorder(root->left);
//     Preorder(root->right);
// }
// void Postorder(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     Postorder(root->left);
//     Postorder(root->right);
//     cout << root->data << " ";
// }
// void SumOfLongestPath(Node *root, int sum, int len, int &maxSum, int &maxLen)
// {
//     if (root == NULL)
//     {
//         if (len > maxLen)
//         {
//             maxLen = len;
//             maxSum = sum;
//         }
//         else if (len == maxLen)
//         {
//             maxSum = max(sum, maxSum);
//         }
//         return;
//     }

//     sum += root->data;

//     SumOfLongestPath(root->left, sum, len + 1, maxSum, maxLen);
//     SumOfLongestPath(root->right, sum, len + 1, maxSum, maxLen);
// }
// void Flatten(Node *root)
// {
//     Node *curr = root;
//     while (curr)
//     {
//         if (curr->left)
//         {
//             Node *pred = curr->left;
//             while (pred->right)
//             {
//                 pred = pred->right;
//             }

//             pred->right = curr->right;
//             curr->right = curr->left;
//             curr->left = NULL;
//         }
//         curr = curr->right;
//     }

//     LevelOrderTraversal(root);
// }
// pair<bool, int> CheckBalancedTree(Node *root)
// {
//     if (root == NULL)
//     {
//         pair<int, int> p = make_pair(true, 0);
//         return p;
//     }

//     pair<bool, int> left = CheckBalancedTree(root->left);
//     pair<bool, int> right = CheckBalancedTree(root->right);

//     bool op1 = left.first;
//     bool op2 = right.first;
//     bool op3 = abs(left.second - right.second) <= 1;

//     pair<bool, int> ans;
//     ans.second = max(left.second, right.second) + 1;
//     if (op1 && op2 && op3)
//     {
//         ans.first = true;
//     }
//     else
//     {
//         ans.first = false;
//     }
//     return ans;
// }
// pair<bool, int> CheckSumTree(Node *root)
// {
//     if (root == NULL)
//     {
//         pair<bool, int> p = make_pair(true, 0);
//         return p;
//     }
//     if (root->left == NULL && root->right == NULL)
//     {
//         pair<bool, int> p = make_pair(true, root->data);
//         return p;
//     }

//     pair<bool, int> left = CheckSumTree(root->left);
//     pair<bool, int> right = CheckSumTree(root->right);

//     bool op1 = left.first;
//     bool op2 = right.first;
//     bool op3 = root->data == left.second + right.second;

//     pair<bool, int> ans;
//     if (op1 && op2 && op3)
//     {
//         ans.first = true;
//         ans.second = 2 * root->data;
//     }
//     else
//     {
//         ans.first = false;
//     }
//     return ans;
// }
// pair<int, int> MaxSumNonAdj(Node *root)
// {
//     if (root == NULL)
//     {
//         pair<int, int> p = make_pair(0, 0);
//         return p;
//     }

//     pair<int, int> left = MaxSumNonAdj(root->left);
//     pair<int, int> right = MaxSumNonAdj(root->right);

//     pair<int, int> ans;
//     ans.first = root->data + left.second + right.second;
//     ans.second = max(left.first, left.second) + max(right.first, right.second);

//     return ans;
// }
// Node *SolveKthAncestor(Node *root, int k, int node)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }
//     if (root->data == node)
//     {
//         return root;
//     }

//     Node *left = SolveKthAncestor(root->left, k, node);
//     Node *right = SolveKthAncestor(root->right, k, node);

//     if (left != NULL && right == NULL)
//     {
//         k--;
//         if (k <= 0)
//         {
//             k = INT_MAX;
//             return root;
//         }
//         return left;
//     }
//     if (left == NULL && right != NULL)
//     {
//         k--;
//         if (k <= 0)
//         {
//             k = INT_MAX;
//             return root;
//         }
//         return right;
//     }
//     return NULL;
// }
// void KthAncestor(Node *root)
// {
//     int k = 1;
//     int node = 4;

//     Node *res = SolveKthAncestor(root, k, node);
//     cout << k << "th Ancestor : ";
//     if (res->data == NULL || res->data == node)
//     {
//         cout << -1 << endl;
//     }
//     else
//     {
//         cout << res->data << endl;
//     }
// }
// void VerticalOrderTraversal(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     map<int, map<int, vector<int> > > Nodes;
//     queue<pair<Node *, pair<int, int> > > q;
//     q.push(make_pair(root, make_pair(0, 0)));

//     while (!q.empty())
//     {
//         Node *node = q.front().first;
//         int hl = q.front().second.first;
//         int level = q.front().second.second;
//         q.pop();

//         Nodes[hl][level].push_back(node->data);

//         if (node->left)
//         {
//             q.push(make_pair(node->left, make_pair(hl - 1, level + 1)));
//         }
//         if (node->right)
//         {
//             q.push(make_pair(node->right, make_pair(hl + 1, level + 1)));
//         }
//     }

//     for (auto i : Nodes)
//     {
//         cout << i.first << " : ";
//         for (auto j : i.second)
//         {
//             for (auto k : j.second)
//             {
//                 cout << k << " ";
//             }
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> arr;
//     for (int i = 0; i < n; i++)
//     {
//         int input;
//         cin >> input;
//         arr.push_back(input);
//     }

//     Node *root = NULL;
//     int index = 0;
//     // root = BuildTreeFromDFS(root, index, arr);
//     // Input :
//     // n = 13
//     // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7

//     BuildTreeFromBFS(root, arr);
//     // Input :
//     // n = 7
//     // 1 2 3 4 5 6 7

//     cout << "Tree Traversal : " << endl;
//     LevelOrderTraversal(root);

//     // Easy problems

//     cout << "Leaf Nodes : ";
//     LeafNode(root);
//     cout << endl;

//     cout << "Height / Depth : " << HeightDepth(root) << endl;

//     cout << "Width / Diameter : " << Diameter(root).first << endl;

//     cout << "Spiral / Zig-Zag Traversal : ";
//     Spiral(root);
//     cout << endl;

//     int n1 = 4, n2 = 6;
//     cout << "LCA of Binary Tree : " << LCA(root, n1, n2)->data << endl;

//     cout << "Root to Leaf Sum : " << RootLeafSum(root) << endl;

//     // All Views

//     cout << "Top View : ";
//     TopView(root);

//     cout << "Bottom View : ";
//     BottomView(root);

//     cout << "Left View : ";
//     vector<int> Leftarr;
//     LeftView(root, Leftarr, 0);
//     for (int i = 0; i < Leftarr.size(); i++)
//     {
//         cout << Leftarr[i] << " ";
//     }
//     cout << endl;

//     cout << "Right View : ";
//     vector<int> Rightarr;
//     RightView(root, Rightarr, 0);
//     for (int i = 0; i < Rightarr.size(); i++)
//     {
//         cout << Rightarr[i] << " ";
//     }
//     cout << endl;

//     cout << "Boundary View : ";
//     BoundaryView(root);
//     cout << endl;

//     // Inorder Predorder PostOrder
//     cout << "Inorder Traversal : ";
//     Inorder(root);
//     cout << endl;

//     cout << "Preorder Traversal : ";
//     Preorder(root);
//     cout << endl;

//     cout << "Postorder Traversal : ";
//     Postorder(root);
//     cout << endl;

//     // Medium Level

//     // Sum of Longest Path
//     int maxSum = INT_MIN;
//     int maxLen = 0;
//     int sum = 0;
//     int len = 0;

//     cout << "Sum of Longest Path : ";
//     SumOfLongestPath(root, sum, len, maxSum, maxLen);
//     cout << maxSum << endl;

//     cout << "Flatten Tree " << endl;
//     // Flatten(root);

//     cout << "Balanced Tree : " << CheckBalancedTree(root).first << endl;

//     cout << "Check Sum Tree : " << CheckSumTree(root).first << endl;

//     cout << "Max Sum of Non Adjacent Node : ";
//     pair<int, int> result = MaxSumNonAdj(root);
//     cout << max(result.first, result.second) << endl;

//     KthAncestor(root);

//     VerticalOrderTraversal(root);

//     return 0;
// }