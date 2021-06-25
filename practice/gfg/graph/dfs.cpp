// DFS recursive 
void dfs(int s, vector<int> adj[], vector<bool> &vis, vector<int> &ans) {
    vis[s] = true;
    ans.push_back(s);

    for (auto u: adj[s]) {
        if (vis[u] == false) {
            dfs(u, adj, vis, ans);
        }
    }
}

vector<int> dfs_of_graph(int V, vector<int> adj[]) {
    vector<bool> vis(V, false); 
    vector<int> ans;
    for (int i = 0; i < V; i++) {
        if (vis[i] == false) {
            dfs(i, adj, vis, ans);
        }
    }
    return ans;
}

