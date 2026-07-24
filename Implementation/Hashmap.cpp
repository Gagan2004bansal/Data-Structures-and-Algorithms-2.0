#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        int key;
        int value;
        Node* next;
    
    Node(int key, int value) {
        this -> key = key;
        this -> value = value;
        this -> next = nullptr;
    }
};

class HashMap {
    vector<Node*> table;
    int capacity;

    int hashFunc(int key) {
        return key % capacity;
    }

    public:
    HashMap(int capacity = 10){
        this -> capacity = capacity;
        table.resize(capacity, nullptr);
    }   

    void put(int key, int value){
        
        int index = hashFunc(key);
        Node* head = table[index];

        while(head != NULL) {
            if(head -> key == key) {
                head -> value = value;
                return;
            }
            head = head -> next;
        }

        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void remove(int key){
        int index = hashFunc(key);

        Node* head = table[index];
        Node* prev = NULL;

        while(head != NULL) {
            if(head -> key == key) {
                if(prev == NULL) {
                    table[index] = head -> next;
                }
                else {
                    prev -> next = head -> next;
                }

                delete head;
                return;
            }

            prev = head;
            head = head -> next;
        }
    }

    int get(int key) {
        
        int index = hashFunc(key);

        Node* head = table[index];
        while(head != NULL){
            if(head -> key == key) {
                return head -> value;
            }
            head = head -> next;
        }

        return -1;
    }
};

int main() {

    HashMap mapp;

    mapp.put(1, 10);
    mapp.put(2, 20);
    mapp.put(3, 30);

    mapp.remove(2);

    cout << mapp.get(2) << endl; 

    return 0;
}