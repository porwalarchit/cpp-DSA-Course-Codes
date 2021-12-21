#include<iostream>
using namespace std;

int numberofOnesinBinary(int n){
    int count = 0;
    while(n != 0){
        n = n & (n-1);
        count++;
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    cout<<numberofOnesinBinary(n);
    return 0;
}