#include<iostream>
using namespace std;

void merge(int arr[], int s, int mid, int e){
	
	
    int size1 = mid-s+1;
    int size2 = e-mid;

    int *leftarray = new int[size1];
    int *rightarray = new int[size2];

    for(int i=0; i<size1; i++){
        leftarray[i] = arr[i];
    }
    for(int i=0; i<size2; i++){
        rightarray[i] = arr[mid+1+i];
    }
    int ind1 = 0;
    int ind2 = 0;
    int k = s;

    while(ind1<size1 && ind2<size2){
        if(leftarray[ind1] < rightarray[ind2]){
            arr[k++] = leftarray[ind1++];
        }
        else{
            arr[k++] = rightarray[ind1++];
        }
        k++;
    }

    while(ind1 < size1){
        arr[k++] = leftarray[ind1++];
    }
    while(ind2 < size2){
        arr[k++] = rightarray[ind1++];
    }
    
    delete []leftarray;
    delete []rightarray;
    
}

void mergesort(int arr[], int s, int e){
    if(s>=e){
        return ;
    }

    int mid = s+(e-s)/2;

    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,mid,e);
}

int main(){
    // int n;
    // cin>>n;

    int arr[] = {12,11,13,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    // for(int i=0; i<n; i++){
    //     cin>>arr[i];
    // }

    mergesort(arr,0,n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
