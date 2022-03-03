#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort_Kahn(int N, vector<int> adj[], vector<int> &indegree){
    queue<int> q;
    for(int i=1; i<=N; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return topo;
}

int main(){
    int N, E;
    cin>>N>>E;

    vector<int> adj[N+1];
    vector<int> indegree(N+1, 0);
    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        indegree[v]++;
    }

    vector<int> ans = topoSort_Kahn(N, adj, indegree);
    
    cout<<"Topological sort of the given Graph using Kahn's Algorithm is: ";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

/*
6 6
3 4
4 2
5 1
5 2
6 1
6 3
Topological sort of the given Graph using Kahn's Algorithm is: 5 6 1 3 4 2 
*/