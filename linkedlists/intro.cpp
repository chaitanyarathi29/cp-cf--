#include <iostream>
#include <vector>
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

Node* arrToLL(vector<int> v){
    Node* head = new Node(v[0]);
    Node* hea = head;
    for(int i=1;i<v.size();i++){
        Node* temp = new Node(v[i]);
        head->next = temp;
        head = temp;
    }
    return hea;
}

int main(){

    vector<int>a = {1,3,4,6,7};
    //conversion of arr to linked lists
    Node* head = arrToLL(a);
    
    //insertion
    Node* inser = new Node(10);
    inser->next = head;
    head = inser;
        
    Node* vl = head;
    while(vl!=nullptr){
        cout<<vl->data<<" ";
        vl = vl->next;
    }
    
    cout<<endl;
    
    //deletion of head of ll
    Node* tempty = head;
    head = head->next;
    
    delete tempty;

    while(head!=nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }

    return 0;
}