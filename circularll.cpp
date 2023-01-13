#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"This Value is deleted from the memory : "<<val<<endl;
    }
};

void insertnode(Node* &tail, int element, int d){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else{
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp; 
    }
}

void deletenode(Node* &tail, int element){
     Node* prev = tail;
    Node* curr = prev->next;

    if(tail == NULL){
        cout<<"Linked List is empty."<<endl;
        return;
    }
    else{
        while(curr->data != element){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    
}

void print(Node* &tail){

    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }
    while(tail != temp);
    cout<<endl;

}

int main(){
   Node* tail = NULL;

   insertnode(tail,5,6);
   print(tail);

   insertnode(tail,6,7);
   print(tail);

   insertnode(tail,7,8);
   print(tail);

   insertnode(tail,8,9);
   print(tail);

   insertnode(tail,6,10);
   print(tail);

   deletenode(tail,7);
   print(tail);

    return 0;
}