#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &vis, vector<int> &ans){
    //Adding current Node to the ans and also marking it as visited.
    ans.push_back(node);
    vis[node]=1;
    
    //Traverse a node and see its adjoint nodes.
    for(auto it : adj[node]){
        if(vis[it]==0){
            //If the adj. node is unvisited then call recursive fn. for that Node.
            DFS(it, adj, vis, ans);
        }
    }
}

//This fn. will help in traversing all components of graph.
vector<int> buildDFS(int N, vector<int> adj[]){
    //'ans' vector will store final after DFS traversal.
    vector<int> ans;

    vector<bool> vis(N+1, 0);

    for(int i=1; i<N+1; i++){
        if(vis[i]==0){
            //Calling the recursive fn. for the Node which is not visited.
            //The code will come here for different components.
            DFS(i, adj, vis, ans);
        }
    }
    return ans;
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

    //Final Vector after DFS traversal.
    vector<int> ans = buildDFS(N, adj);

    cout<<"Graph after DFS Traversal: ";
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

/*
7 6
1 2
2 4
2 7 
4 6
6 7
3 5
*/