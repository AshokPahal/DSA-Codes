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
};

int length(Node* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}

void getmiddle(Node* head){
    Node* temp = head;
    Node* slow = temp;
    Node* fast = temp->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    cout<<slow->data<<endl;
}

//finding the middle node of the linked list
void middle(Node* &head){

    getmiddle(head);

    // int len = length(head);
    // int ans = (len/2)+1;

    // Node* temp = head;
    // int count = 1;

    // while(count<ans){
    //     temp = temp->next;
    //     count++;
    // }
    // cout<<temp->data<<endl;

}

void insertathead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
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
    Node* node = new Node(20);

    Node* head = node;

    insertathead(head,21);
    print(head);

    insertathead(head,22);
    print(head);

    insertathead(head,23);
    print(head);

    insertathead(head,24);
    print(head);

    middle(head);


    return 0;
}