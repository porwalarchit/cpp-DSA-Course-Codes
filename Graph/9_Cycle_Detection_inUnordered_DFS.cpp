#include<bits/stdc++.h>
using namespace std;

bool isCycle(int node,int parent, vector<int> adj[], vector<int> &vis){
    vis[node]=1;
    for(auto it : adj[node]){
        if(vis[it]==0){
            if(isCycle(it, node, adj, vis))
                return true;
        }
        else if(it!=parent)
            return true;
    }
    return false;
}

bool checkCycle(int N, vector<int> adj[]){
    vector<int> vis(N+1, 0);
    for(int i=1; i<=N; i++){
        if(vis[i]==0){
            int parent = -1;
            if(isCycle(i,parent, adj, vis))
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
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(checkCycle(N, adj))
        cout<<"Cycle Exists";
    else
        cout<<"No Cycle Exists";
}