// Ques-> Check the ith bit is set or not
// Approach-> Left Shift by 1 for (i-1) times.
// 1<<(i-1)
// Calculate (n&i) will give 0 or 1; 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i;
    cin>>n>>i;

    if(n & (1<<(i-1)))
        cout<<"Yes";
    else
        cout<<"No";
}