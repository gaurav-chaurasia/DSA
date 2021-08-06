void bfs(int curr, vector<int> adj[], vector<bool> &vis, vector<int> &ans) {
    queue<int> q;

    vis[curr] = true;
    q.push(curr);
    while(!q.empty()) {
        int item = q.front(); q.pop();
        
        // process the element
        ans.push_back(item);

        for (int u: adj[item]) {
            if (vis[u] == false) {
                vis[u] = true;
                q.push(u);
            }
        }
    }
}

void bfs_better_implimentation(int curr, vector<int> adj[], vector<bool> &vis, vector<int> &ans) {
    queue<int> q;

    vis[curr] = true;
    q.push(curr);
    
    while(!q.empty()) {
        // this way we travel level by level
        int size = q.size();
        
        while (size--) {
            int item = q.front(); q.pop();
            ans.push_back(item);

            for (int u: adj[item]) {
                if (vis[u] == false) {
                    vis[u] = true;
                    q.push(u);
                }
            }
        }
    }
}

vector<int> bfs_of_graph(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<bool> vis(V, false);

    for (int i = 0; i < V; ++i) {
        if (vis[i] == false) {
            bfs(i, adj, vis, ans);
        }
    }

    return ans;
}