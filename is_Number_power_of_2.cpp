#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int n1 = n-1;
    if((n & n1) == 0){
        cout<<n<<" is power of 2";
    }
    else{
        cout<<n<<" is not power of 2";
    }
    return 0;
}