#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next = NULL;
    Node* prev = NULL;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<val<<" : this value is deleted from the memory"<<endl;
    }
};

void insertathead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertatTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertatposition(Node* &head, Node* &tail, int pos, int d){
    if(pos == 1){
        insertathead(head,d);
        return;
    }

    int count = 1;
    Node* temp = head;
    while(count <= pos-1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        insertatTail(tail,d);
        return;
    }

    Node* insertPos = new Node(d);
    insertPos->next = temp->next;
    temp->next->prev = insertPos;
    temp->next = insertPos;
    insertPos->prev = temp;

}

void deleteNode(Node* &head, int pos){
    if(pos == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev1 = NULL;

        int count = 1;
        while(count<pos){
            prev1 = curr;
            curr = curr->next;
            count++;
        }

        curr->prev = NULL;
        prev1->next = curr->next;
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
    Node* node = new Node(6); 
    Node* head = node;
    Node* tail = node;

    insertathead(head,5);
    print(head);

    insertathead(head,3);
    print(head);

    insertathead(head,2);
    print(head);

    insertatTail(tail,7);
    print(head);

    insertatposition(head,tail,2,4);
    print(head);

    deleteNode(head,3);
    print(head);


    return 0;
}