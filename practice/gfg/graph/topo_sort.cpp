// methode 1
// using DFS
// in this approach we use a stack and after each recursion call
// we put element in stack
// https://youtu.be/rZv_jHZva34?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw

void topo_sort_helper(int curr, vector<int> adj[], vector<bool> &vis, stack<int> &st) {
    vis[curr] = true;

    for (int u: adj[curr]) {
        if (vis[u] == false) {
            topo_sort_helper(u, adj, vis, st);
        }
    }

    st.push(curr);
}

vector<int> topo_sort(int V, vector<int> adj[]) {
    stack<int> st;
    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++) {
        if (vis[i] == false) {
            topo_sort_helper(i, adj, vis, st);
        }
    }

    vector<int> topo;
    while(!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
}

// methode 2
// using BFS
// https://youtu.be/rZv_jHZva34?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
vector<int> topo_sort(int V, vector<int> adj[]) {
    queue<int> q;
    vector<int> indegree(V, 0);

    // calculate indegree
    for (int i = 0; i < V; i++) {
        for (int u: adj[i]) {
            indegree[u]++;
        }
    }

    // pushing all the element to queue with indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()) {
        int item = q.front();
        q.pop();
        topo.push_back(item);

        for(int u: adj[item]) {
            indegree[u]--;
            if (indegree[u] == 0) {
                q.push(u);
            }
        }
    }

    return topo;
}