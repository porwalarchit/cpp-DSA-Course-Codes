// Number of set bits in a number N.
// Inbuilt Function->
// For integer-> __builtin_popcount(int)
// For Long Long-> __builtin_popcountll(int)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int c=0;
    while(n>0){
        n = n & n-1;
        c++;
    }
    cout<<c;
}