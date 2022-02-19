#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> v, int k){
    int n = v.size();
    int zerocount = 0;
    int i = 0;
    int ans = 0;

    for(int j=0; j<n; j++){
        if(v[j]==0)
            zerocount++;
        
        while(zerocount>k){
            if(v[i]==0)
                zerocount--;
            i++;
        }

        ans = max(ans, j-i+1);
    }
    return ans;
}

int main(){
    vector<int> v = {1,1,0,0,0,1};
    int k = 2;

    cout<<maxConsecutiveOnes(v, k);
}
// 1,1,1,0,0,0,1,1,1,1,0