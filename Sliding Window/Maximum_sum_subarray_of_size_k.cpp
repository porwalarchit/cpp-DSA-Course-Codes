// PS- Given an array of size n and also given a window size k. You need to find maximum sum for every window.
// The number of elements in final answer will be n-k+1.
// Link- https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

#include<bits/stdc++.h>
using namespace std;

int main(){
    // Inputs
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int k;
    cin>>k;

    
    int i=0, j=0, mx=INT_MIN, sum=0;
    while(j<n){
        sum += a[j];// Calculation

        if((j-i+1) < k) // Check if window size is less than k.
        {
            j++;
        }

        else if((j-i+1) == k) // When window size is equal to k.
        {
            mx = max(mx, sum);
            sum -= a[i];
            i++;
            j++;
        }
    }

    // Output
    cout<<mx<<endl;
}

/* Inputs
7
2 5 1 8 2 9 1
3
*/