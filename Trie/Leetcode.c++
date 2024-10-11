#include <iostream>
using namespace std;
class Trie{
    public:
    int data;
    Trie *children[10];
    bool isTerminal;

    Trie(int data){
        this -> data = data;
        for(int i = 0; i<=9; i++){
            children[i] = NULL;
        }
        this -> isTerminal = false;
    }
};
void Insert(Trie* root, int start, int n){
    if(start == n+1){
        root -> isTerminal = true;
        return;
    }

    Trie* child;
    int temp = start % 10;
    if(root -> children[temp] != NULL){
        child = root -> children[temp];
    }
    else{
       child = new Trie(temp);
       root -> children[temp] = child;
    }

    Insert(child, start+1, n);
}
int search(Trie* root, int start, int k, int n){
    if (start == k){
        return root -> data;
    }
    if(start == n){
        return 0;
    }

    Trie* child;
    int temp = start % 10;
    if(root->children[temp] != NULL){
        child = root -> children[temp];
    }
    else{
        return 0;
    }

    return child -> data * 10 + search(child, start+1, k, n);
}
int main(){

    Trie* root = new Trie(-1);
    int n;
    cin >> n;
    Insert(root, 1, n);
    int k;
    cin >> k;
    cout << search(root, 1, k, n) << endl;
    return 0;
}