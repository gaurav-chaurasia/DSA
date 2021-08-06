class Solution {
public:
    void dfs(int curr, unordered_map<int, vector<int>> &adj, vector<bool> &vis) {
        vis[curr] = true;
        for (int u: adj[curr]) {
            if (vis[u] == false) {
                dfs(u, adj, vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n, false);
        
        // making adj list
        unordered_map<int, vector<int>> adj; 
        for (int i = 0; i < connections.size(); i++) {
            adj[connections[i][1]].push_back(connections[i][0]);
            adj[connections[i][0]].push_back(connections[i][1]);
        }
        int edges = connections.size();
        
        // counting all the components in the graph
        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i] == false) {
                components += 1;
                dfs(i, adj, vis);
            }
        }
        
        // if number of edges is less then required to connect all the element
        if (edges < n - 1) 
            return -1;
        
        // finding redundant edges 
        // and if they are more or equal to needed edges 
        int redundant = edges - ((n - 1) - (components - 1));
        if (redundant >= (components - 1)) 
            return components - 1;
        
        return -1;
    }
};