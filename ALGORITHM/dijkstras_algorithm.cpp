// dijkstras_algorithm algo is used to find the shorted path of all the nodes
// from a given sourse node with positive weights

// but it do not detect negative weight cycle 
// and can give wrong answer in case of negative edge 

// Dijkstra's Algorithm
// since we use priority_queue it takes log(n) time for every push and pop operation
// the total time complexity would be O(E + VLogV)
// the total space complexity would be O(V) + O(V)

void shortest_path_undirected_weighted_graph(int V, vector<vector<int>> adj[], int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;

    pq.push({dist[src], src});

    while (!pq.empty()) {
        pair<int, int> node = pq.top();
        pq.pop();

        for (vector<int> u : adj[node.second]) {
            // u[0] v , u[1] w

            // if there exist path with smaller dist
            // update the dist of that node
            if (dist[u[0]] > node.first + u[1]) {
                dist[u[0]] = node.first + u[1];
                pq.push({dist[u[0]], u[0]});
            }
        }
    }

    return dist;
}
