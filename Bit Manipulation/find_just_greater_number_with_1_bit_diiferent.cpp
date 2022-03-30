// Ques-> Find the smallest number greater than ‘n’ with exactly 1 bit different in binary form.
// Approach-> Just change the first 0 to 1, that we get while moving from left to right.
// For doing this Add 1 to the number and then apply bitwise OR.

#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin>>n;

    cout<< (n | n+1) <<endl;
}