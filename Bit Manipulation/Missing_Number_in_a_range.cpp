// X= Take XOR of all elements from 1 to N.
// Y= Take XOR of numbers given in array
// Use A^A=0 property.
// X^Y will give the answer;
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n-1];
    for(int i=0; i<n-1; i++){
        cin>>a[i];
    }

    int X=0;
    for(int i=1; i<=n; i++){
        X = X^i;
    }

    int Y=0;
    for(int j=0; j<n-1; j++){
        Y = Y^a[j];
    }
    int ans = X^Y;
    cout<<ans;
}