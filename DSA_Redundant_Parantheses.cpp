// (a+b) - Not having Redundant Parantheses
// ((a+b)) - Redundant Parantheses

#include<bits/stdc++.h>
using namespace std;

bool isRedundant(string s){
    stack<char> st;

    for(int i=0; i<s.size(); i++){
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            st.push(s[i]);
        
        else if(s[i]=='(')
            st.push(s[i]);

        else if(s[i]==')'){
            if(st.top() == '(')
                return true;
            
            while(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                st.pop();
            }

            st.pop();
        }
    }

    return false;
}

int main(){
    string s;
    cin>>s;

    if(isRedundant(s))
        cout<<"Redundant Parantheses."<<endl;
    else
        cout<<"Not having Redundant Parantheses."<<endl;

    return 0;
}