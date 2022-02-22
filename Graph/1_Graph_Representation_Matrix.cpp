#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, E;
    //taking number of Nodes and Edges as Input
    cin>>N>>E;

    //declare the Adjacent Matrix
    bool mat[N+1][N+1];
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++)
            mat[i][j] = 0;
    }

    //taking edges as Input
    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        mat[u][v]=1;
        mat[v][u]=1;
    }

    cout<<"\nAdjacency Matrix of the given graph is:\n";
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

/* Input
5 7
1 2 
1 3
1 5
2 3
3 4
2 4
5 3
*/