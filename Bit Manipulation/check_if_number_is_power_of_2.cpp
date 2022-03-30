// Ques- Determine a number is power of 2 or not.
// If numbers of setBit is 1 then number can be represented in power of 2.
// Else number cannot be represented in power of 2.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n<0){
        cout<<0;
        return 0;
    }
    int c=0;
    while(n>0){
        n = n & n-1;
        c++;
    }
    if(c==1)
        cout<<1;
    else
        cout<<0;
}