#include<iostream>
#include<string>
using namespace std;

string moveAllx(string s){
    if(s.length() == 0)
        return "";
    char ch = s[0];
    string restStr = moveAllx(s.substr(1));

    if(ch == 'x'){
        return (restStr+ch);
    }
    return (ch+restStr);
}

int main(){
    string str;
    cin>>str;

    cout<<moveAllx(str);
}