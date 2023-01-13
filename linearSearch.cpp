#include<iostream>
using namespace std;

bool search(int arr[], int n, int key){
    if(n == 0){
        return false;
    }

    if(arr[0] == key){
        return true;
    }
    else{
        int remainingPart = search(arr+1,n-1,key);
        return remainingPart;
    }
}

int main(){
    int n, key;
    cin>>n>>key;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    bool ans = search(a,n,key);
    if(ans){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not Present"<<endl;
    }

    return 0;
}