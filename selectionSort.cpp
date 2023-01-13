#include<iostream>
using namespace std;

void sort(int a[], int n){
    if(n==0 || n==1){
        return ;
    }

    for(int i=0; i<n-1; i++){
        for(int j=1; j<n; j++){
            if(a[j]<a[i])
                swap(a[j],a[i]);
        }
    }

    sort(a+1,n-1);
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    sort(a,n);

    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }cout<<endl;

    return 0;
}