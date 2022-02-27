#include<bits/stdc++.h>
using namespace std;

bool checkBipartite(int it, vector<int>adj[], vector<int> &color){
    queue<int> q;
    q.push(it);
    color[it]=0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto i : adj[node]){
            if(color[i] == -1){
                color[i] = 1 - color[node];
                q.push(i);
            }
            else if(color[i]==color[node]){
                return false;
            }
        }
    }
    return true;
}

bool ifBipartite(int N, vector<int> adj[]){
    vector<int> color(N+1, -1);
    for(int i=0; i<=N; i++){
        if(color[i] == -1){
            if(!checkBipartite(i, adj, color))
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
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans = ifBipartite(N, adj);
    if(ans)
        cout<<"Bipartite Graph";
    else
        cout<<"Not a bipartite Graph";
    
    return 0;
}

/* Inputs
Bipartite Graph
6 6
1 2
2 3
2 5
3 4
4 6
5 4

Not a Bipartite Graph 
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