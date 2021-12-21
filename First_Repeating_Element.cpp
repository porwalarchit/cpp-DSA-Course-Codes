#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    const int N = 1e6+2;
    int idx[N];
    int minidx = INT32_MAX;
    for(int i=0; i<N; i++)
        idx[i] = -1;
    
    for(int i=0; i<n; i++){
        int j = a[i];
        if(idx[j] != -1){
            minidx = min(minidx,idx[j]);
        }
        else{
            idx[j] = i;
        }
    }

    if(minidx == INT_MAX)
        cout<<-1;
    else
        cout<<minidx+1;
    
    return 0;
}