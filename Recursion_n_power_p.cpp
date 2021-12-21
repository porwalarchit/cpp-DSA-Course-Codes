#include<iostream>
using namespace std;

int Power(int n, int p){
    if(p==0)
        return 1;
    return n * Power(n, p-1);
}

int main(){
    int n,p;
    cin>>n>>p;

    cout<<Power(n,p);
}