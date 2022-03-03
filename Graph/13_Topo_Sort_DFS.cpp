//Topological Sort
//Only possible for: Directed Acyclic Graph (DAG)

#include<bits/stdc++.h>
using namespace std;

stack<int> st;
void topoSort(int node, vector<int> adj[], vector<int> & vis){
    vis[node]=1;
    for(auto it : adj[node]){
        if(vis[it]==0){
            topoSort(it, adj, vis);
        }
    }
    st.push(node);
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

    vector<int> vis(N+1, 0);
    for(int i=1; i<=N; i++){
        if(vis[i]==0){
            //call function.
            topoSort(i, adj, vis);
        }
    }

    cout<<"Topological sort of the given Graph is: ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
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
ANS = 6 5 3 4 2 1 
*/