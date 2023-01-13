#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
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

void insertAtHead(Node* &head, int d){

    Node* temp = new Node(d);
    temp->next = head;
    head = temp;

}

void insertAtTail(Node* &tail, int d){

    Node*temp = new Node(d);

    temp->next = NULL;
    tail->next = temp;
    tail = temp;

}

void insertAtPostion(Node* &head, Node* &tail, int position, int d){

    if(position == 1){
        insertAtHead(head, d);
        return;
    }
    Node* temp = head;
     int count = 1;
     while(count< position-1){
        temp = temp -> next;
        count++;
     }

     if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
     }

     Node* nodeAtPosition = new Node(d);

     nodeAtPosition ->next = temp -> next;
     temp -> next = nodeAtPosition;

}

void deleteNode(Node* &head, int pos){
    Node* temp = head;
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int count = 1;
        while(count<pos){
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

    }
    
}


void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* node = new Node(10);

    Node* head = node;
    Node* tail = node;

    print(head);

    insertAtHead(head,9);
    print(head);

    insertAtHead(head,8);
    print(head);

    insertAtTail(tail,12);
    print(head);

    insertAtTail(tail,14);
    print(head);

    insertAtPostion(head,tail,5,13);
    print(head);

    deleteNode(head,2);
    print(head);

    return 0;
}