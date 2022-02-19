#include<bits/stdc++.h>
using namespace std;

int getMax_Area(vector<int> v){
    stack<int> st;
    int n = v.size();
    int ans = 0;

    for(int i=0; i<n; i++){
        while(!st.empty() && v[st.top()]>v[i]){
            int t = st.top();
            int h = v[t];
            st.pop();

            if(st.empty())
                ans = max(ans, h*i);
            
            else{
                int len = i-st.top()-1;
                ans = max(ans, h*len);
            }

        }
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> v = {2,1,5,6,2,3};

    int ans = getMax_Area(v);
    cout<<ans;
}