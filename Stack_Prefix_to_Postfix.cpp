#include<iostream>
#include<stack>
using namespace std;

string pretoPostfix(string s){
    stack<string> stk;

    for(int i=s.length()-1; i>=0; i--){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            stk.push(string(1, s[i]));
        }

        else{
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();

            stk.push(op1 + op2 + s[i]);
        }
    }

    return stk.top();
}

int main(){
    string s = "*+AB-CD";
    cout<<"Postfix: "<<pretoPostfix(s)<<endl;
}