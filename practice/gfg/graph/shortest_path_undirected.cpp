// find out shortest path in undirected graph 
// from scr to all other nodes


vector<int> shortest_path_undirected_graph(int N, vector<vector<int>> &adj[], int src) {
    vector<int> dist(N, INT_MAX);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int u: adj[node]) {
            if (dist[node] + 1 < dist[u]) {
                dist[u] = dist[node] + 1;
                q.push(u);
            }
        }
    }

    return dist;
}