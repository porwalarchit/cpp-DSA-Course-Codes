#include<bits/stdc++.h>
#include<stack>
using namespace std;

string PrefixtoInfix(string s){
    reverse(s.begin(), s.end());
    stack<string> stk;

    for(int i=0; i<s.length(); i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
            stk.push(string(1, s[i]));
        }

        else{
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();

            stk.push("(" + op1 + s[i] + op2 + ")");
        }
    }
    return stk.top();
}

int main(){
    string s = "+A*-*BC*/D^EFGH";
    cout<<PrefixtoInfix(s);
}