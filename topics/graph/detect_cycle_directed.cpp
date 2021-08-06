// methode 1
// https://www.youtube.com/watch?v=uzVUw90ZFIg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=12
bool detect_cycle_directed_util(int curr, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsV) {
    vis[curr] = true;
    dfsV[curr] = true;

    for (int it: adj[curr]) {
        if (vis[it] == false) {
            if (detect_cycle_directed_util(it, adj, vis, dfsV)) {
                return true;
            }
            else if (dfsV[it] == true) {
                return true;
            }
        }
    }

    dfsV[curr] = false;
    return false;
}

bool detect_cycle_directed(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    vector<bool> dfsV(V, false);

    for (int i = 0; i < V; ++i) {
        if (vis[i] == false) {
            if (detect_cycle_directed_util(i, adj, vis, dfsV)) {
                return true;
            }
        }
    }
    return false;
}