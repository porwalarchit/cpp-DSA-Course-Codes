#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int Start=0, End=n;
    int mid;
    while(Start<=End){
        mid=(Start+End)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key)
            End=mid-1;
        else if(arr[mid]<key)
            Start=mid+1;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    int key;
    cin>>key;

    cout<<binarySearch(arr, n, key)<<endl;

}