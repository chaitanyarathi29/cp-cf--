#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        Node* back;
        int data;
        Node* next;

    Node(int data){
        this->back = nullptr;
        this->data = data;
        this->next = next;
    }
};

Node* creation(vector<int>vec){

    Node* head = new Node(vec[0]);
    Node* prev = head;

    for(int i=1;i<vec.size();i++){
        Node* temp = new Node(vec[i]);
        temp->back = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;

}

void traversal(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* returnsTail(Node* head){

    Node* tail = head;
    while(tail->next!=nullptr){
        tail = tail->next;
    }   
    return tail;

}

void reverseTraversal(Node* tail){
    
    Node* temp = tail;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->back;
    }
}

int main(){

    vector<int>vec = {10,12,34,21,4,78};

    Node* head = creation(vec);

    Node* tail = returnsTail(head);

    traversal(head);
    reverseTraversal(tail);


    
    return 0;
}