#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){

    string s;
    cin>>s;
    int n = s.size();
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            if(s[j]<s[j+1])
                swap(s[j], s[j+1]);  
    }
    cout<<s;

    string s1;
    cin>>s1;

    sort(s1.begin(), s1.end(), greater<int>());
    cout<<s1;
}