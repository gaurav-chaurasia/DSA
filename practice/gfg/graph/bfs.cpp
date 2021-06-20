void bfs(int V, vector<int> adj[]) {
    vector<int> ans;
    vector<bool> vis(V, false);
    queue<int> q;

    q.push(0);
    vis[0] = true;
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