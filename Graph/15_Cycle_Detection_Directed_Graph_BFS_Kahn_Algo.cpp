#include<bits/stdc++.h>
using namespace std;

bool checkCycle_Kahn(int N, vector<int> adj[], vector<int> &indegree){
    int count=0;
    queue<int> q;
    for(int i=1; i<=N; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        count++;
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
    if(count==N){
        return false;
    }
    else
        return true;
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

    bool ans = checkCycle_Kahn(N, adj, indegree);
    if(ans)
        cout<<"Cycle Exists";
    else
        cout<<"No cycle Exists";
    return 0;
}
/*
9 10
1 2
2 3
3 4
3 6
6 5
7 2
7 8
8 9
9 7
Cycle Exists


6 6
5 1
5 2
6 1
6 3
3 4
4 2
No cycle Exists
*/