#include<bits/stdc++.h>
using namespace std;

vector<int> stock_Span(vector<int> a){
    stack<pair<int, int>> st;
    vector<int> ans;

    for(int i=0; i<a.size(); i++){
        int days = 1;

        while(!st.empty() && st.top().first <= a[i]){
            days += st.top().second;
            st.pop();
        } 
        st.push({a[i], days});
        ans.push_back(st.top().second);
    }

    return ans;
}

int main(){
    vector<int> a = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans = stock_Span(a);
        
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
}