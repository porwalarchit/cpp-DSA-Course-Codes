#include<bits/stdc++.h>
using namespace std;

string DecimaltoHexadecimal(int n)
{
    int x=1,rem=0;
    string ans = "";
    while(x<n)
        x*=16;
    x/=16;

    while(x>0)
    {
        rem=n/x;
        n-=rem*x;
        x/=16;
        if(rem<=9)
        {
            ans= ans + to_string(rem);
        }
        else
        {
            char c = 'A' + rem - 10;
            ans.push_back(c);
        }
    }
    return ans;
}

int  main()
{
    int n;
    cout<<"Enter Decimal Number :";
    cin>>n;

    cout<<"Hexadecimal Representation = "<<DecimaltoHexadecimal(n);
    return 0;
}