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

// void insertAtTail(Node* &tail, int d){

//     Node*temp = new Node(d);

//     temp->next = NULL;
//     tail->next = temp;
//     tail = temp;

// }

// void insertAtPostion(Node* &head, Node* &tail, int position, int d){

//     if(position == 1){
//         insertAtHead(head, d);
//         return;
//     }
//     Node* temp = head;
//      int count = 1;
//      while(count< position-1){
//         temp = temp -> next;
//         count++;
//      }

//      if(temp->next == NULL){
//         insertAtTail(tail,d);
//         return;
//      }

//      Node* nodeAtPosition = new Node(d);

//      nodeAtPosition ->next = temp -> next;
//      temp -> next = nodeAtPosition;

// }

// void deleteNode(Node* &head, int pos){
//     Node* temp = head;
//     if(pos == 1){
//         Node* temp = head;
//         head = head->next;
//         temp->next = NULL;
//         delete temp;
//     }
//     else{
//         Node* curr = head;
//         Node* prev = NULL;
//         int count = 1;
//         while(count<pos){
//             prev = curr;
//             curr = curr->next;
//             count++;
//         }
//         prev->next = curr->next;
//         curr->next = NULL;
//         delete curr;

//     }
    
// }

void removeDuplicate(Node* &head){
   if(head == NULL){
        return;
    }

    Node* curr = head;

    while(curr->next != NULL){
        if(curr->data != curr->next->data){
            curr = curr->next;
        }
        else{
            Node* nextnode = curr->next->next;
            Node* nodetodel = curr->next;
            delete nodetodel;
            curr->next = nextnode;
        }
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
    Node* node = new Node(5);

    Node* head = node;
    //Node* tail = node;

    print(head);

    insertAtHead(head,4);
    print(head);

    insertAtHead(head,3);
    print(head);

    insertAtHead(head,3);
    print(head);

    insertAtHead(head,2);
    print(head);

    removeDuplicate(head);
    print(head);


    return 0;
}