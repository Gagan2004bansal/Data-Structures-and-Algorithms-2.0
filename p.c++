#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};
void Build(Node* &root){
    int data;
    cin >> data;
    if(data == -1){
        return;
    }
    root = new Node(data);

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        int leftData;
        cin >> leftData;
        if(leftData != -1){
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        int rightData;
        cin >> rightData;
        if(rightData != -1){
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }
}
void Postorder(Node* root){
    if(root == NULL){
        return;
    }

    Postorder(root -> left);
    Postorder(root -> right);

    cout << root -> data << " ";
}

void Leaf(Node* root, int &count){
    if(root == NULL){
        return;
    }

    Leaf(root -> left, count);
    if(root -> left == NULL && root -> right == NULL){
        count++;
    }
    Leaf(root -> right, count);
}

pair<int, int> diameter(Node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int, int> leftCall = diameter(root -> left);
    pair<int, int> rightCall = diameter(root -> right);

    int op1 = leftCall.first;
    int op2 = rightCall.first;
    int op3 = leftCall.second + rightCall.second + 1;

    pair<int,int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(leftCall.second, rightCall.second) + 1;

    return ans;
}

pair<bool, int> BalancedTree(Node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if(root -> left == NULL && root -> right == NULL){
        pair<bool, int> p = make_pair(true, 1);
    }

    pair<bool, int> leftCall = BalancedTree(root -> left);
    pair<bool, int> rightCall = BalancedTree(root -> right);

    bool op1 = leftCall.first;
    bool op2 = rightCall.first;
    bool op3 = abs(leftCall.second - rightCall.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(leftCall.second, rightCall.second) + 1;
    if(op1 && op2 && op3){
        ans.first = true;
    }
    else{
        ans.first = false;
    }
    return ans;
}

pair<bool, int> checkSum(Node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if(root -> left == NULL && root -> right == NULL){
        pair<bool, int> p = make_pair(true, root -> data);
        return p;
    }

    pair<bool,int> leftCall = checkSum(root -> left);
    pair<bool,int> rightCall = checkSum(root -> right);

    bool op1 = leftCall.first;
    bool op2 = rightCall.first;
    bool op3 = root -> data == (leftCall.second + rightCall.second);

    pair<bool, int> ans;
    if(op1 && op2 && op3){
        ans.first = true;
        ans.second = 2 * root -> data;
    }
    else{
        ans.first = false;
    }
    return ans;
}

int main(){

    Node* root = NULL;
    Build(root);
    int count = 0;
    
    cout << checkSum(root).first << endl;
    return 0;
}