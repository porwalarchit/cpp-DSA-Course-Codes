#include<iostream>
using namespace std;

int firstocc(int arr[], int n, int i, int key){
    if(i==n)
        return -1;
    
    if(arr[i]==key)
        return i;
    
    return firstocc(arr, n, i+1, key);
}

int lastocc(int arr[], int n, int i, int key){
    if(i==n)
        return -1;

    int restarr = lastocc(arr, n, i+1, key);

    if(restarr != -1)
        return restarr;
    
    if(arr[i]==key)
        return i;
    return -1;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int key;
    cin>>key;

    cout<<firstocc(arr, n, 0, key)<<endl;
    cout<<lastocc(arr, n, 0, key);
    return 0;
}