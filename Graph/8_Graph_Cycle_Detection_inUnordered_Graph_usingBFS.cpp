#include <bits/stdc++.h>
using namespace std;

bool checkCycle(int i, vector<int> adj[], vector<bool> &vis, int comp){
    queue<pair<int, int>> q;
    q.push({i, -1});
    vis[i] = 1;

    while (!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto it : adj[node]){
            if (vis[it] == 0){
                q.push({it, node});
                vis[it] = 1;
            }
            else if (parent != it){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int N, vector<int> adj[]){
    int component = 0;
    vector<bool> vis(N + 1, 0);
    for (int i = 0; i <= N; i++){
        if (vis[i] == 0){
            component++;
            if (checkCycle(i, adj, vis, component)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int N, E;
    cin >> N >> E;

    vector<int> adj[N + 1];
    for (int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans = isCycle(N, adj);
    if(ans){
        cout<<"Cycle Found";
    }
    else{
        cout<<"Cycle Not found";
    }
}

/* Input
11 10
1 2
2 4
3 5
5 6
5 10
6 7
7 8
8 9
8 11
9 10
*/