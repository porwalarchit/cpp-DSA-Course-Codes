// Ques- Determine a number is power of 4 or not.
// If numbers of setBit is 1 and also the numbers of bits in number are odd then number can be represented in power of 4.
// Else number cannot be represented in power of 4.

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
    int tmp = n;

    while(n>0){
        n = n & n-1;
        c++; // Calculate number of set bits.
    }
    if(c>1)
        cout<<0;
    else{
        int k = floor(log2(tmp)+1); // Count numbers of bits present in the given number.

        if(k&1==1) // Check number is even or odd.
            cout<<1; // Odd Number of bits present in number.
        else
            cout<<0; //Even Number of bits present in number.
    }
}