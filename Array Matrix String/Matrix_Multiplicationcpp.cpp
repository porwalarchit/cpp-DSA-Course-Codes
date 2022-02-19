// 2D Array Video

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n1,n2,n3,n4;
    cout<<"Enter Size of First Matrix: ";
    cin>>n1>>n2;
    int M1[n1][n2];
    cout<<"Enter Elements of First Matrix\n";
    for(int i=0; i<n1; i++)
        for(int j=0; j<n2; j++)
            cin>>M1[i][j];
    
    cout<<"Enter Size of Second Matrix: ";
    cin>>n3>>n4;
    if(n2 != n3){
        cout<<"Column of First Matrix should be equal to Row of Second Matrix";
        return 0;
    }

    int M2[n3][n4];
    cout<<"Enter Elements of Second Matrix\n";
    for(int i=0; i<n3; i++)
        for(int j=0; j<n4; j++)
            cin>>M2[i][j];
    
    //Matrix Multiplication
    int M3[n1][n4];
    
    for(int i=0; i<n1; i++){
        for(int k=0; k<n4; k++){
            int sum=0;
            for(int j=0; j<n2; j++){
                sum+= M1[i][j] * M2[j][k];
            }
            M3[i][k] = sum;
        }
    }

    cout<<"After Matrix Multiplication: \n";
    for(int i=0; i<n1; i++){
        for(int j=0; j<n4; j++)
            cout<<M3[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}