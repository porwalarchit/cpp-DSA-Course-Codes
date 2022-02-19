#include<bits/stdc++.h>
using namespace std;

vector<int> maximumSlidingWindow(vector<int> v, int k){
    multiset<int, greater<int>> s;
    vector<int> ans;

    for(int i=0; i<k; i++)
        s.insert(v[i]);
    ans.push_back(*s.begin());

    for(int i=k; i<v.size(); i++){
        s.erase(s.lower_bound(v[i-k]));
        s.insert(v[i]);
        ans.push_back(*s.begin());
    }

    return ans;
}

int main(){
    vector<int> v = {1,3,1,-3,5,3,6,7};
    int k = 4;
    vector<int> ans = maximumSlidingWindow(v, k);
    for(auto i : ans)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}