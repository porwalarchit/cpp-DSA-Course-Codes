// Link- https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
// PS- Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.
// Use List/Queue to store negative numbers and as the window moves, remove the number if it doesn't exist in current window.
// to get the answer array we need to push first element from list when the window size is hit.
// Window size will be n-k+1.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int k;
    cin>>k;

    int i=0, j=0;
    list<int> ls;
    vector<int> ans;
    while(j<n){
        if(a[j]<0){
            ls.emplace_back(a[j]);
        }
        
        if(j-i+1 < k){
            j++;
        }
        
        else if(j-i+1==k){
            if(!ls.empty())
                ans.push_back(ls.front());
            else
                ans.push_back(0);
            
            if(a[i]==ls.front())
                ls.pop_front();
            
            i++;
            j++;
        }
    }
    for(auto x : ans)  
        cout<<x<<" ";
    cout<<endl;
}

/* Input
8
12 -1 -7 8 -15 30 16 28
3
*/