// Kth smallest element in a BST
// #include <iostream>
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
// Node *insertDataInBST(Node *root, int data)
// {
//     // Base Case
//     if (root == NULL)
//     {
//         root = new Node(data);
//         return root;
//     }

//     if (data > root->data)
//     {
//         root->right = insertDataInBST(root->right, data);
//     }
//     else
//     {
//         root->left = insertDataInBST(root->left, data);
//     }

//     return root;
// }
// void inputBST(Node *&root)
// {
//     int data;
//     cin >> data;

//     while (data != -1)
//     {
//         root = insertDataInBST(root, data);
//         cin >> data;
//     }
// }
// int KthSmallest(Node *root, int &i, int k)
// {
//     if (root == NULL)
//     {
//         return -1;
//     }

//     // left
//     int left = KthSmallest(root->left, i, k);
//     if (left != -1)
//     {
//         return left;
//     }
//     i++;
//     // Node
//     if (i == k)
//     {
//         return root->data;
//     }
//     // Right
//     return KthSmallest(root->right, i, k);
// }
// void Solve(Node *root, int k)
// {
//     int i = 0;
//     int ans = KthSmallest(root, i, k);

//     cout << "Kth smallest element : " << ans << endl;
// }
// int main()
// {
//     Node *root = NULL;
//     cout << "Enter elemets in BST \n";
//     inputBST(root);
//     int k;
//     cout << "Enter which Kth element : ";
//     cin >> k;
//     Solve(root, k);
//     return 0;
// }

// Kth Largest element in a BST
#include <iostream>
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
Node *insertDataInBST(Node *root, int data)
{
    // Base Case
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = insertDataInBST(root->right, data);
    }
    else
    {
        root->left = insertDataInBST(root->left, data);
    }

    return root;
}
void inputBST(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertDataInBST(root, data);
        cin >> data;
    }
}
void Kthlargest(Node *root, vector<int> &i)
{
    if (root == NULL)
    {
        return;
    }

    Kthlargest(root->left, i);
    i.push_back(root->data);
    Kthlargest(root->right, i);
}
void Solve(Node *root, int k)
{
    vector<int> i;
    Kthlargest(root, i);
    int ans = i[i.size() - k + 1];
    cout << "Kth Largest element : " << ans << endl;
}
int main()
{
    Node *root = NULL;
    cout << "Enter elemets in BST \n";
    inputBST(root);
    int k;
    cout << "Enter which Kth element : ";
    cin >> k;
    Solve(root, k);
    return 0;
}