#include<iostream>
using namespace std;

void countSort(int arr[], int n){
    int k = -1;
    for(int i=0; i<n; i++)
        k = max(k, arr[i]);
    
    int countarr[k+1] = {0};

    for(int i=0; i<n; i++){
        countarr[arr[i]]++;
    }

    for(int i=1; i<=k; i++)
        countarr[i] += countarr[i-1];

    int outputarr[n];
    for(int i=n-1; i>=0; i--)
        outputarr[--countarr[arr[i]]] = arr[i];
    
    for(int i=0; i<n; i++)
        arr[i] = outputarr[i];
    
}

int main(){
    int n;
    cout<<"Enter N: ";
    cin>>n;

    int arr[n];
    cout<<"Enter Elements of Array: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    countSort(arr, n);

    cout<<"Sorted Array :: \n";
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    
}