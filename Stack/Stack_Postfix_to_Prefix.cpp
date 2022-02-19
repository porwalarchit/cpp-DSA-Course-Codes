#include<iostream>
#include<stack>
using namespace std;

string postToPrefix(string s){
    stack<string> stk;

    for(int i=0; i<s.length(); i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            stk.push(string(1, s[i]));
        }

        else{
            string op2 = stk.top();
            stk.pop();
            string op1= stk.top();
            stk.pop();

            stk.push(s[i] + op1 + op2);
        }
    }

    string ans;
    while(!stk.empty()){
        ans += stk.top();
        stk.pop();
    }

    return ans;
}

int main(){
    string s = "AB+CD-*";
    cout<<"Prefix: "<<postToPrefix(s);
}