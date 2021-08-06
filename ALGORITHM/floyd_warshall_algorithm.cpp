// this algo is used to find shortest path between any two node
// of directed weighted graph with positive or negative edges

const int INF = (int)1e9;

// graph taken in terms of adj matrix
vector<vector<int>> floyd_warshall(int n, vector<vector<int>> graph) {
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // initializing dist with graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // intuition behind this algo is
    // to bring node between any two node and if it is smaller relax the dist
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return dist;
}