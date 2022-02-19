#include<bits/stdc++.h>
using namespace std;

int DecimaltoOctal(int n)
{
    int x=1,ans=0,rem=0;
    while(x<=n){
            x*=8;
    }
    x/=8;

    while(x>0)
    {
        rem=n/x;
        ans=ans*10 + rem;
        n=n-rem*x;
        x/=8;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter Decimal Number : ";
    cin>>n;

    cout<<"Octal Representation = "<<DecimaltoOctal(n);
    return 0;
}