// this algorithm is used to find the strongly connected algorithm
// this is basically done by following backward DFS of there process time

// TC -> O(V + E)
// SC -> O(N)

// steps
// 1: find topo sort of graph
// 2: transpose the graph
// 3: apply DFS from last of the topo sort

void dfs(int curr, vector<int> adj[], vector<bool> &vis, stack<int> st) {
    vis[curr] = true;

    for (int u: adj[i]) {
        if (vis[u] == false) {
            dfs(u, adj, vis, st);
        }
    }

    st.push(curr);
}

void rev_dfs(int curr, vector<int> adj[], vector<bool> &vis, stack<int> st) {
    vis[curr] = true;
    cout << curr << " ";

    for (int u: adj[i]) {
        if (vis[u] == false) {
            dfs(u, adj, vis, st);
        }
    }
}

void kosaraju_algorithm(int n, vector<int> adj[]) {
    // step 1: finding topo sort
    stack<int> st; // to store topo sort of the graph
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (vis[i] == false) {
            dfs(i, adj, vis, st);
        }
    }


    // step 2: generating transpose of the graph
    vector<int> transpose[n];
    for (int u = 0; u < n; u++) {
        vis[u] = false;
        for (int v: adj[u]) {
            transpose[v].push_back(u);
        }
    }


    // step 3: calling dfs on transpose graph in reverse topo sort order
    while(!st.empty()) {
        int node = st.top();
        st.pop();

        if (vis[node] == false) {
            cout << "SCC: "
            rev_dfs(node, transpose, vis);
            cout << endl;
        }
    }

}