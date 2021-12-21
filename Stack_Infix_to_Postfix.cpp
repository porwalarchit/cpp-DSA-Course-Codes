#include<iostream>
#include<stack>
using namespace std;

int prec(char ch){
    if(ch=='^')
        return 3;
    else if(ch=='*' || ch=='/')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    else
        return -1;
}

string InfixtoPostfix(string s){
    stack<char> stk;
    string res ;

    for(int i=0; i<s.length(); i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res += s[i];
        }

        else if(s[i]=='('){
            stk.push(s[i]);
        }

        else if(s[i]==')'){
            while(!stk.empty() && stk.top()!='('){
                res += stk.top();
                stk.pop();
            }

            if(!stk.empty()){
                stk.pop();
            }
        }

        else{
            while(!stk.empty() && prec(stk.top())>prec(s[i])){
                res += stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }
    }

    while(!stk.empty()){
        res += stk.top();
        stk.pop();
    }

    return res;
}

int main(){
    string s = "(a*b+c)-f/(e^g+d)";
    cout<<InfixtoPostfix(s)<<endl;
}
