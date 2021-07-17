## kahn's algorithm
- kahn's algorithm is used to generate on of topological sort of the graph 


```cpp
    vector<int> topo_sort(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> topo;
        vector<int> indegree(V, 0);

        // calculating indegree of the elements of the graph
        for (int i = 0; i < V; i++) {
            for (int u: adj[i]) {
                indegree[u]++;
            }
        }

        // pushing element with indegree = 0 to the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front(); 
            q.pop();
            topo.push_back(node);

            for (int u: adj[node]) {
                indegree[u]--
                if (indegree[u] == 0) {
                    q.push(u);
                }
            }
        }

        return topo;
    }
```