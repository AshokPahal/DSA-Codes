#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next = NULL;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

class stack {

    public:
    Node* top = NULL;

    stack(){
        top = NULL;
    }

    void push(int val){
        Node* temp = new Node(val);

        if(!temp){
            cout<<"Stack Overflow"<<endl;
        }
        temp->data = val;
        temp->next = top;
        top = temp;
    }

    bool isEmpty(){
        if(top == NULL){
            return true;
        }
        else
            return false;
    }

    int peek(){
        if(top == NULL){
            return -1;
        }
        else{
            return top->data;
        }
    }

    void pop(){

        Node* temp;
        if(top == NULL){
            cout<<"stack underflow"<<endl;
        }
        else{
            temp = top;
            top = top->next;
            free(temp);
        }
    }

    void display(){
        Node* temp;
        if(top == NULL){
            cout<<"Stack underflow"<<endl;
        }
        else{
            temp = top;
            while(temp != NULL){
                cout<<temp->data<<"->";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
    }

};

int main(){

    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();

    s.pop();
    s.display();

    return 0;
}