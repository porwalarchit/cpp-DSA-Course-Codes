#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int a[], int n){
    int count=1;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++)
        {
            if(a[j] < a[i]){
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
        cout<<"After Pass "<<count<<" : "; 
        for(int i=0; i<n; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        count++;
    }
}

int main(){
    int n;
    cout<<"Enter Number of Elements in Array: ";
    cin>>n;

    int a[n];
    cout<<"Enter values of Array: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    SelectionSort(a, n);
}