#include<bits/stdc++.h>
using namespace std;

bool checkCycleDFS(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsvis){
    vis[node]=1;
    dfsvis[node]=1;

    for(auto it : adj[node]){
        if(vis[it]==0){
            if(checkCycleDFS(it, adj, vis, dfsvis))
                return true;
        }
        else if(dfsvis[it]==1){
            return true;
        }
    }
    dfsvis[node]=0;
    return false;
}

bool ifCycle(int N, vector<int> adj[]){
    vector<int> vis(N+1, 0);
    vector<int> dfsvis(N+1, 0);
    for(int i=1; i<=N; i++){
        if(vis[i]==0){
            if(checkCycleDFS(i, adj, vis, dfsvis))
                return true;
        }
    }
    return false;
}

int main(){
    int N, E;
    cin>>N>>E;

    vector<int> adj[N+1];
    for(int i=0; i<E; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    bool ans = ifCycle(N, adj);
    if(ans)
        cout<<"Cycle Detected";
    else{
        cout<<"No Cycle Detected";
    }

}

/*
9 10
1 2
2 3
3 4
3 6
4 5
6 5
7 2
7 8
8 9
9 7
Cycle Detected

6 6
1 2
2 3
3 4
3 6
4 5
6 5
No Cycle Detected
*/