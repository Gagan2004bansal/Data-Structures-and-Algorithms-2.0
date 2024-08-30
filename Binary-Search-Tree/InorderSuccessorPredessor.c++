// Inorder Sucessor and Predecessor using Vector
//   T.C  ->  O(N)
//   S.C  ->  O(N)
//  Approach - 1

// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;

//     // Constructor
//     Node(int data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };
// Node *insertDataInBST(Node *root, int data)
// {
//     if (root == NULL)
//     {
//         root = new Node(data);
//         return root;
//     }

//     // If data is greater than root -> data
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
// void Displaying(Node *root)
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
// void Solve(Node *root, vector<int> &Ans)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     Solve(root->left, Ans);
//     Ans.push_back(root->data);
//     Solve(root->right, Ans);
// }
// int main()
// {
//     Node *root = NULL;
//     cout << "Enter Data in BST : ";
//     inputBST(root);
//     // Displaying(root);
//     cout << endl;

//     vector<int> Ans;
//     Solve(root, Ans);

//     int key;
//     cout << "Enter Key : ";
//     cin >> key;

//     int pred = -1, succ = -1;
//     for (int i = 0; i < Ans.size(); i++)
//     {
//         if (i == 0 && Ans[i] == key)
//         {
//             pred = -1;
//             succ = Ans[i + 1];
//             break;
//         }

//         if (Ans[i] == key)
//         {
//             pred = Ans[i - 1];
//             succ = Ans[i + 1];
//             break;
//         }

//         if (i == Ans.size()-1 && Ans[i] == key)
//         {
//             pred = Ans[i-1];
//             succ = -1;
//             break;
//         }

//     }
//     cout << "Predecessor : " << pred << endl;
//     cout << "Successor   : " << succ << endl;
//     return 0;
// }

// Approach - 2  ITERATIVE APPROACH
// T.C -> O(N)
// S.C -> O(1)
#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *insertDataInBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // If data is greater than root -> data
    if (data > root->data)
    {
        root->right = insertDataInBST(root->right, data);
    }
    else
    { // If data is less than root -> data
        root->left = insertDataInBST(root->left, data);
    }

    return root;
}
void inputBST(Node *&root)
{
    int data;
    cout << "Enter All data in BST : ";
    cin >> data;

    while (data != -1)
    {
        root = insertDataInBST(root, data);
        cin >> data;
    }
}
void Displaying(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
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
void Result(Node *root, int key)
{
    int pred = -1;
    int succ = -1;

    Node *temp = root;
    while (root)
    {
        if (key >= root->data)
        {
            root = root->right;
        }
        else
        {
            succ = root->data;
            root = root->left;
        }
    }
    while (temp)
    {
        if (key > temp->data)
        {
            pred = temp->data;
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    cout << "Predecessor : " << pred << endl;
    cout << "Successor   : " << succ << endl;
}
int main()
{
    Node *root = NULL;
    inputBST(root);
    // Displaying Data of BST
    Displaying(root);
    cout << endl;
    int key;
    cout << "Enter key : ";
    cin >> key;
    Result(root, key);
    return 0;
}
