#include<bits/stdc++.h>
using namespace std;

int Three_Sum(vector<int> v, int target){
    sort(v.begin(), v.end());
    int n = v.size();

    for(int i=0; i<n; i++){
        int lo = i+1;
        int hi = n-1;

        while(lo<hi){
            int curr = v[i] + v[lo] + v[hi];
            
            if(curr==target)
                return true;
            if(curr < target)
                lo++;
            else
                hi--;
        }
    }
    return false;
}

int main(){
    vector<int> v = {12,3,7,1,6,9};
    int target = 45;

    cout<<Three_Sum(v, target);
}