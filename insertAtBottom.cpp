#include<iostream>
#include<stack>
using namespace std;

void atbottom(stack<int>& s, int x){
    if(s.empty()){
        s.push(x);
        cout<<s.top()<<" ";
        return;
    }

    int num = s.top();
    s.pop();
    atbottom(s,x);
    s.push(num);
    cout<<s.top()<<" ";
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);

    atbottom(s,6);

    return 0;
}