#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, E;
    cin>>N>>E;

    vector<int> adj[N+1];
    for(int i=0; i<E; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    cout<<"\nAdjacency List of given Ordered Graph is: \n";
    for(int i=0; i<N+1; i++){
        cout<<i<<"-> ";
        for(int j=0; j<adj[i].size(); j++)
            cout<<adj[i][j]<<" ";
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