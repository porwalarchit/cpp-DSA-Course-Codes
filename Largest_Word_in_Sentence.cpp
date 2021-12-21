//Character Array
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    cin.ignore();

    char arr[n+1];
    cin.getline(arr,n);
    cin.ignore();

    int i=0;
    int currlen=0, maxlen=0;
    int Idx=0,endIdx;

    while(1){

        if(arr[i]==' ' || arr[i]=='\0'){
            if(currlen>maxlen){
                maxlen = currlen;
                endIdx=Idx;
            }
            currlen=0;
            Idx = i+1;
        }
        
        else
            currlen++;

        if(arr[i]=='\0'){
            break;
        }

        i++;
    }

    cout<<maxlen<<endl;
    for(int i=0; i<maxlen; i++){
        cout<<arr[i+endIdx];
    }
}