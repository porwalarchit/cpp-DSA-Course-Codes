#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> v, int k){
    deque<int> dq;
    vector<int> ans;

    for(int i=0; i<k; i++){
        while(!dq.empty() && v[dq.back()]<v[i])
            dq.pop_back();
        dq.push_back(i);
    }
    ans.push_back(v[dq.front()]);

    for(int i=k; i<v.size(); i++){
        while(!dq.empty() && v[dq.back()]<v[i])
            dq.pop_back();
        dq.push_back(i);
        ans.push_back(v[dq.front()]);
    }

    return ans;
}

int main(){
    vector<int> v = {1,3,1,-3,5,3,6,7};
    int k = 8;

    vector<int> ans = maxSlidingWindow(v, k);
    for(auto i : ans)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}