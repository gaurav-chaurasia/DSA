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



// dijkstra on grid
typedef pair<int, int> pi;
typedef pair<int, pi> ppi;
class Solution
{
public:
    //Function to return the minimum cost to react at bottom
    //right cell from top left cell.
    // dijkstra's algorithm can be used to determine the answer
    // dijkstra's algo on grid
    int minimumCostPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

        vis[0][0] = true;
        pq.push({grid[0][0], {0, 0}});
        while (!pq.empty())
        {
            auto node = pq.top();
            int dist = node.first;
            int i = node.second.first;
            int j = node.second.second;
            pq.pop();

            if (i == n - 1 and j == n - 1)
            {
                return dist;
            }

            vector<pi> cords = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            for (pi cord : cords)
            {
                if (
                    (i + cord.first < n and i + cord.first >= 0) and
                    (j + cord.second < n and j + cord.second >= 0) and
                    (vis[i + cord.first][j + cord.second] == false))
                {
                    vis[i + cord.first][j + cord.second] = true;
                    pq.push({dist + grid[i + cord.first][j + cord.second], {i + cord.first, j + cord.second}});
                }
            }
        }

        return 0;
    }
};