#include<bits/stdc++.h>
using namespace std;

int BFS(int N, vector<int> adj[])
{
    int count=0;
    bool vis[N + 1] = {0};

    for (int i = 1; i <= N; i++){
        if (vis[i] == 0){
            //Counting number of times code gets inside the if statement.
            count++;
            
            //Using Queue DS for BFS Traversal in Graph
            queue<int> q;
            q.push(i);

            vis[i] = 1;
            while (!q.empty()){
                int node = q.front();
                q.pop();

                for (int j = 0; j < adj[node].size(); j++){
                    if (vis[adj[node][j]] == 0){
                        q.push(adj[node][j]);
                        vis[adj[node][j]] = 1;
                    }
                }
            }
        }
    }
    return count;
}

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

    int count = BFS(N, adj);
    //Apply BFS or DFS

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

Ans- 3 Components
*/