#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, E;
    cin>>N>>E;

    vector<int> adj[N+1];
    //Creating Graph in Vector Form
    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool vis[N+1]={0};
    int count=0;
    for(int i=1; i<=N; i++){
        if(vis[i]==0){
            //Apply BFS or DFS
            count++;
        }
    }
    cout<<count;
}
/*Input
10 7
1 3
3 4
4 6
6 8
2 9
5 7
7 10
*/