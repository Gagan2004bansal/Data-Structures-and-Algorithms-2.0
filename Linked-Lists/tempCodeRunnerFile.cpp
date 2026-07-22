// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
    public:
  int data;
  Node* next;
  Node(int data){
      this->data=data;
      this->next=nullptr;
  }
};
void change(Node* root){
    root->data=93;
}
int main() {
    Node* root=new Node(38);
    cout<<root->data<<endl;
    change(root);
    cout<<root->data;
    

    // Write C++ code here
    

    return 0;
}