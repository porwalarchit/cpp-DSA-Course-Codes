#include<iostream>
#include<stack>
using namespace std;

bool areBracketsBalanced(string s){
    stack<char> stk;
    char x;

    for(int i=0; i<s.length(); i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            stk.push(s[i]);
            continue;
        }

        if(stk.empty())
            return false;
        
        switch (s[i])
        {
        case ')':
            x = stk.top();
            stk.pop();
            if(x=='[' || x=='{')
                return false;
            break;

        case ']':
            x = stk.top();
            stk.pop();
            if(x=='(' || x=='{')
                return false;
            break;
            
        case '}':
            x = stk.top();
            stk.pop();
            if(x=='(' || x=='[')
                return false;
            break;
        }
    }

    if(!stk.empty())
        return false;
    
    return true;
}

int main(){
    string s = "))";
    cout<<areBracketsBalanced(s)<<endl;
}