// You will be given a number x. You have to find the value of XOR of [1, x] i.e 1^2^3^4………………..^x.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    switch (n%4)
    {
    case 0: cout<<n;
            break;
    case 1: cout<<1;
            break;
    case 2: cout<<n+1;
            break;
    case 3: cout<<0;
            break;
    }
}