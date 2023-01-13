#include<iostream>
using namespace std;

int sumByRecursion(int arr[], int n){
    if(n == 0){
        return 0;
    }

    if(n == 1){
        return arr[n];
    }

    int remainingPart = sumByRecursion(arr+1,n-1);
    int sum = arr[0]+remainingPart;
    return sum;
    
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int sum = sumByRecursion(arr,n);
    cout<<sum<<endl;

    return 0;
}
