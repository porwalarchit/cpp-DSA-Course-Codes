//In 2D Arrays Challenge Video

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    // Matrix Transpose
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            swap(arr[i][j] , arr[j][i]);
        }
    }

    cout<<"Matrix Transpose: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}