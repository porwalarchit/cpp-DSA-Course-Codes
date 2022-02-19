//In 2D Arrays Challenge Video

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int target;
    cin>>target;
    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    bool found = false;
    int r=0, c=m-1;
    while(r<n and c>=0){
        if(arr[r][c] == target){
            found = true;
            break;
        }
        if(arr[r][c] > target)
            c--;
        else
            r++;
    }

    if(found)
        cout<<"Element Found\n";
    else
        cout<<"Element not Found\n";
    
    return 0;
}