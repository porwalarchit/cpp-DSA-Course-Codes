#include<iostream>
#include<string>
using namespace std;

void reverseString(string s){
    if(s.length()==0)
        return;
    string restStr = s.substr(1);
    reverseString(restStr);
    cout<<s[0];
}

int main(){
    string str;
    cin>>str;

    reverseString(str);
}