#include<iostream>
#include<stack>
using namespace std;

string PostfixtoInfix(string s){
    stack<string> stk;

    for(int i=0; i<s.length(); i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            stk.push(string(1, s[i]));
        }

        else{
            string op2 = stk.top();
            stk.pop();
            string op1 = stk.top();
            stk.pop();

            stk.push("(" + op1 + s[i] + op2 + ")");
        }
    }

    return stk.top();
}

int main(){
    string s = "ABC*DE/-+";
    cout<<PostfixtoInfix(s)<<endl;
}