#include<iostream>
using namespace std;

int partition(int a[], int s, int e){
    int pivot = a[s];
    int count = 0;

    for(int i=s+1; i<=e; i++){
        if(a[i] <= pivot){
            count++;
        }
    }
    int pivotIndex = s+count;
    swap(a[s],a[pivotIndex]);
    
    while(s<pivotIndex && e>pivotIndex){
        while(a[s] <= a[pivotIndex]){
            s++;
        }
        while(a[e] > a[pivotIndex]){
            e--;
        }
        if(s<pivotIndex && e>pivotIndex){
            swap(a[s++],a[e--]);
        }

    }
}

void quicksort(int a[], int s, int e){
    
    if(s>=e){
        return ;
    }

    int p = partition(a,s,e);

    quicksort(a,s,p-1);

    quicksort(a,p+1,e);

}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    quicksort(arr,0,n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}