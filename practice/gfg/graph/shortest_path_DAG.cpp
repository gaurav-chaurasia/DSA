// finding shortest path from scr to all other nodes in DAG
// this can be solved in just the O(V + E) time complexity 
// DAG = Directed Acyclic Graph
void topo_sort(int curr, vector<vector<pair<int, int>>> &adj, vector<int> &vis, stack<int> &st) {
    vis[curr] = 1;

    for (pair<int, int> it: adj[curr]) {
        if (vis[it.first] == 0) {
            topo_sort(it.first, adj, vis, st);
        }
    }

    st.push(curr);
}

vector<int> shortest_path_DAG(int src, vector<vector<pair<int, int>>> &adj[]) {
    int n = adj.size();

    stact<int> st;
    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++) {
        if (vis[i] == 0) {
            topo_sort(i, adj, vis, st);
        }
    }
    // now i would be having toposort with me in stack

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX) {
            for (pair<int, int> it: adj[node]) {
                if (dist[node] + it.second < dist[it.first]) {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    return dist;
}
