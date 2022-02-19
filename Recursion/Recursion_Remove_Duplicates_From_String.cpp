#include<iostream>
#include<string>
using namespace std;

string removeDuplicates(string s){
    if(s.length() == 0)
        return " ";

    char ch = s[0];
    string restStr = removeDuplicates(s.substr(1));

    if(ch == restStr[0])
        return restStr;
    
    return (ch + restStr);
}

int main(){
    string str;
    cin>>str;

    cout<<removeDuplicates(str);
}