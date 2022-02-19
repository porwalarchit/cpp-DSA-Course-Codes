#include<iostream>
using namespace std;

int getBit(int n, int pos){
    return ((n & (1<<pos)) != 0);
}

void unique(int arr[], int n){
    int xorsum = 0;
    for(int i=0; i<n; i++){
        xorsum = xorsum ^ arr[i];
    }

    int tempsum = xorsum;
    int pos = 0;
    int setbit = 0;
    
    while(setbit != 1){
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum>>1;
    }

    int newxor = 0;
    for(int i=0; i<n; i++){
        if(getBit(arr[i], pos-1)){
            newxor = newxor ^ arr[i];
        }
    }

    cout<<endl<<newxor<<" "<<(newxor^tempsum);
}

int main(){
    int arr[] = {1,2,3,4,5,5,4,3,2,1,56,33};
    unique(arr, 12);
}