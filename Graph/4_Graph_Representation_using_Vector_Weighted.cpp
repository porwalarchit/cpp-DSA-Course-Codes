#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, E;
    cin>>N>>E;

    vector<pair<int, int>> adj[N+1];

    for(int i=0; i<N+1; i++){
        //Taking Node, Edge and Weight as Input
        int u,v,wt;
        cin>>u>>v>>wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    cout<<"\nAdjacency List of given Weighted Graph is: \n";
    for(int i=0; i<N+1; i++){
        cout<<i<<"-> ";
        for(int j=0; j<adj[i].size(); j++){
            cout<<"{"<<adj[i][j].first<<","<<adj[i][j].second<<"} ";
        }
        cout<<endl;
    }
}

/* Input
5 7
1 2 59
1 3 65
1 5 54
2 3 34
3 4 45
2 4 53
5 3 61
*/