#include<bits/stdc++.h>
using namespace std;

bool checkBipartiteDFS(int node, vector<int> adj[], vector<int> &color){
    for(auto it : adj[node]){
        if(color[it] == -1){
            color[it] = 1 - color[node];
            if(!checkBipartiteDFS(it, adj, color))
                return false;
        }
        else if(color[it]==color[node]){
            return false;
        }
    }
    return true;
}

bool ifBipartite(int N, vector<int> adj[]){
    vector<int> color(N+1, -1);
    for(int i=1; i<=N; i++){
        if(color[i]==-1){
            color[i]=0;
            if(!checkBipartiteDFS(i, adj, color))
                return false;
        }
    }
    return true;
}

int main(){
    int N, E;
    cin>>N>>E;

    vector<int> adj[N+1];
    for(int i=0; i<E; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans = ifBipartite(N, adj);
    if(ans)
        cout<<"Bipartite Graph";
    else
        cout<<"Not a bipartite Graph";
}

/*
Bipartite Graph Example
6 6
1 2
2 3
2 5
3 4
4 6
5 4

Not Bipartite Graph Example
8 8
1 2
2 3
2 8
3 4
4 5
5 6
5 8
6 7
*/