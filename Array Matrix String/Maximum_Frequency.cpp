#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin>>s;

    int count[26] = {0};
    for(int i=0; i<s.size(); i++){
        count[s[i]-'a']++;
    }

    int ans = 0;
    char charAns = 'a';
    for(int i=0; i<26; i++){
        if(count[i] > ans){
            ans = count[i]; 
            charAns = i + 'a';
        }
    }
    cout<<ans<<" "<<charAns;
}