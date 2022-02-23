#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int N, vector<int> adj[])
{
    vector<int> ans;
    bool vis[N + 1] = {0};

    for (int i = 1; i <= N; i++){
        if (vis[i] == 0){
            //Using Queue DS for BFS Traversal in Graph
            queue<int> q;
            q.push(i);

            vis[i] = 1;
            while (!q.empty()){
                int node = q.front();
                ans.push_back(node);
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
    return ans;
}

int main()
{
    // Taking Nodes and Edges as Input
    int N, E;
    cin >> N >> E;

    // Creating vector to represent graph in Vector Form
    vector<int> adj[N + 1];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans = BFS(N, adj);
    cout << "\nGraph after BFS Traversal: ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}

/* Input
7 6
1 2
2 3
2 7
3 5
5 7
4 6
*/