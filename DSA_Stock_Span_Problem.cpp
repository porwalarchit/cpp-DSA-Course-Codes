#include<bits/stdc++.h>
using namespace std;

vector<int> stock_Span(vector<int> prices){
    stack<pair<int, int>> st;
    vector<int> ans;

    for(int i=0; i<prices.size(); i++){
        int days = 1;
        while(!st.empty() && st.top().first<=prices[i]){
            days += st.top().second;
            st.pop();
        }

        st.push({prices[i], days});
        ans.push_back(st.top().second);
    }
    
    return ans;
}

int main(){
    vector<int> v = {100, 80, 60, 70, 60, 75, 85};

    vector<int> ans = stock_Span(v);
    for(auto i: ans)
        cout<<i<<" ";
    cout<<endl;

    return 0;
}