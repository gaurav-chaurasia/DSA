// bellman_ford algo is used to find the shortest path of all the nodes 
// from a given sourse node in a weighted graph with no negative cycle
// it can have negative weights but should not have negative weight cycle

// it also detects if negative weights cycle present in graph

vector<int> bellman_ford(int nodes, vector<int> adj[]) {
    // this will be the sourse node from which all the dist will be calculated
    int source = 0;

    // this array will store all the dist from source node
    vector<int> dist(nodes, INT_MAX);
    dist[source] = 0;

    for (int count = 1; count <= nodes - 1; ++count) { 
        // performing relaxation for all the edges 
        for (int i = 0; i < nodes; i++) {
            for (auto u: adj[i]) {
                dist[u] = min(dist[u], dist[i] + w);
            }
        }
    }

    // to detect if negative weights cycle present or not 
    // we have to do relaxation one more time and if any of dist gets updated
    // means it has negative weights cycle

    return dist;
}