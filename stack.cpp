#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s.pop();

    cout<<" Top Element : "<<s.top()<<endl;

    s.pop();
    s.pop();
    s.pop();

    if(s.empty()){
        cout<<"stack is empry"<<endl;
    }
    else{
        cout<<"stack not empty"<<endl;
    }

    return 0;
}