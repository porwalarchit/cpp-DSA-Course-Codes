#include<iostream>
using namespace std;

int main(){
    int n,s;
    cin>>n>>s;

    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    
    int i=0, j=0, start=-1, end=-1, sum=0;

    while(j<n && sum+a[j]<=s){
        sum += a[j];
        j++;
    }
    if(sum == s){
        cout<< i+1 <<" "<<j;
        return 0;
    }
    while(j<n){
        sum += a[j];
        while(sum>s){
            sum -= a[i];
            i++;
        }

        if(sum==s){
            start = i+1;
            end = j+1;
            break;
        }
        j++;
    }

    cout<<start<<' '<<end;

    return 0;
}