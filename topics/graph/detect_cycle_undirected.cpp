// method 1 
// using graph coloring 
// problem here is to find if cycle is present in the graph or not
// approach here we r going to follow is
// use below video for explanation
// https://youtu.be/L0DcePeWHnM

bool is_cycle_util(int curr, vector<int> adj[], vector<int> visited) {
    if (visited[curr] == 2)
        return true;

    visited[curr] = 1;
    for (int u: adj[curr]) {
        if (visited[u] == 1) {
            visited[u] = 2;
        }
        else {
            if(is_cycle_util(u, adj, visited))
                return true;
        }
    }
    return false;
}

bool is_cycle(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);

    for (int i = 0; i < V; ++i) {
        visited[i] = 1;
        if (is_cycle_util(i, adj, visited)) {
            return true;
        }
        visited[i] = 0;
    }
    return false;
}


// method 2
// 
bool is_cycle_util(int curr, int parent, vector<int> adj[], vector<bool> &visited) {
    visitied[curr] = true;

    for (int u: adj[curr]) {
        if (visited[u] == false) {
            if (is_cycle_util(u, curr, adj, visited)) {
                return true;
            }
        }
        else if (u != parent) {
            return true;
        }
    }
}

bool is_cycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);

    for (int i = 0; i < v; i++){ 
        if (visited[i] == false) {
            if (is_cycle_util(i, -1, adj, visited))
                return true;
        }
    }

    return false;
}