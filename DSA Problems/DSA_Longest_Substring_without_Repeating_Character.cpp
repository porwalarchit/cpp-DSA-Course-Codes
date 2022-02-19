#include<bits/stdc++.h>
using namespace std;

int longest_Substring(string s){
    vector<int> dict(256, -1);
    int maxLen = 0;
    int start = -1;

    for(int i=0; i<s.size(); i++){
        if(dict[s[i]] > start){
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        maxLen = max(maxLen, i-start);
    }
    return maxLen;
}

int main(){
    string s;
    cin>>s;

    cout<<longest_Substring(s);
}