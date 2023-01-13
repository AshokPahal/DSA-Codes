#include<iostream>
// #include<stack>
using namespace std;

class Stack {

    public:
        int *arr;
        int size;
        int top;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size-top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack overflow "<<endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        if(top >= 0){
            return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){

    //stack using array
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    cout<<st.peek()<<endl;
    st.pop();

    cout<<st.peek()<<endl;
    st.pop();

    cout<<st.peek()<<endl;
    st.pop();

    cout<<st.peek()<<endl;
    st.pop();

    cout<<st.peek()<<endl;
    st.pop();

    if(st.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    
    // Stack using STL
    // stack<int> s;

    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);

    // s.pop();

    // cout<<" Top Element : "<<s.top()<<endl;

    // s.pop();
    // s.pop();
    // s.pop();

    // if(s.empty()){
    //     cout<<"stack is empry"<<endl;
    // }
    // else{
    //     cout<<"stack not empty"<<endl;
    // }

    return 0;
}