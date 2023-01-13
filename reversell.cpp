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

void insertAtHead(Node* &head, int d){

    Node* temp = new Node(d);
    temp->next = head;
    head = temp;

}

Node* reverse1(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    Node* restnode = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;

    return restnode;
}

//recursive method to reverse a linked list
// void reversell(Node* &head, Node* &curr, Node* &prev){
//     if(curr == NULL){
//         head = prev;
//         return;
//     }
//     Node* forward = curr->next;
//     reversell(head,forward,curr);
//     curr->next = prev;
// }


//direct method to reverse a linked list
Node* reverse(Node* &head){

    return reverse1(head);

    // Node* curr = head;
    // Node* prev = NULL;
    //reversell(head,curr,prev);
//     Node* temp = head;
//     if(temp == NULL || temp->next == NULL){
//         cout<<head<<endl;
//         return;
//     }
//     else{
//         Node* curr = head;
//         Node* prev = NULL;
//         Node* forward = NULL;

//         while(curr != NULL){
//             forward = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = forward;
            
//         }
//         head = prev;
//     }
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

    insertAtHead(head,11);
    print(head);

    insertAtHead(head,12);
    print(head);

    insertAtHead(head,13);
    print(head);

    insertAtHead(head,14);
    print(head);

    reverse(head);
    print(head);

    return 0;
}