#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, E;
    //Taking number of Nodes and Edges as Input
    cin>>N>>E;

    // Creating vector of Size greatar than Number of Nodes because of zero indexing.
    vector<int> adj[N+1];

    //Taking edges as Input
    for(int i=0; i<E; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<"\nAdjacency List of given Unordered Graph is: \n";
    for(int i=0; i<N+1; i++){
        cout<<i<<"-> ";
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
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