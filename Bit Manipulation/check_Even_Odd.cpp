//WAP to check if a number is Even or Odd
//Even      Odd
//2-> 0010  1-> 0001
//4-> 0100  3-> 0011
//6-> 0110  5-> 0101
//Observation: 0 at LSB in Even Numbers and 1 at LSB in Odd Numbers.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    if(n&1==1)
        cout<<"Odd";
    else
        cout<<"Even";
}