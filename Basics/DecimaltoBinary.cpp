#include<bits/stdc++.h>
using namespace std;

int DecimaltoBinary(int n)
{
    int x=1,ans=0,rem=0;
    while(x<=n){
            x*=2;
    }
    x/=2;

    while(x>0)
    {
        rem=n/x;
        ans=ans*10 + rem;
        n=n-rem*x;
        x/=2;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter Decimal Number : ";
    cin>>n;

    cout<<"Binary Representation = "<<DecimaltoBinary(n);
    return 0;
}