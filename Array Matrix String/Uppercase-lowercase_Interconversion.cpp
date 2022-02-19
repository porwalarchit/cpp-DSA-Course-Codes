#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    cin>>str;
    //cin.ignore();

    //Lowercase to Uppercase
    for(int i=0; i<str.length(); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
    }
    cout<<str<<endl;

    //Uppercase to lowercase
    for(int i=0; i<str.size(); i++)
        if(str[i]>='A'  && str[i]<='Z')
            str[i] += 32;
    cout<<str;

}