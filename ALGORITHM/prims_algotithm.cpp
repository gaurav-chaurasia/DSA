// implimentation of prims algorithm
// which basically counts minimum spanning tree
// brout force approach
void prims_algo(vector<pair<int, int>> adj[]) {
    int n = adj.size();
    
    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);

    // starting from 0'th node
    key[0] = 0;
    parent[0] = -1;

    // we are going to have N - 1 edge in minimum spanning tree
    for(int count = 0; count < n - 1; count++) {
        // find the minimum key in all the nodes [0, n)
        int mini = INT_MAX, u;
        for (int i = 0; i < n; i++) {
            if (mst[i] == false and key[i] < mini) {
                mini = key[i], u = i;
            }
        }


        // visite the minimun key node 
        // iterate over all its adjusent nodes
        mst[u] = true;

        for (int it: adj[u]) {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false and w < key[v])
                parent[v] = u, key[v] = w;
        }

    }
}


// optimised with pq
void prims_algo(vector<pair<int, int>> adj[]) {
    int n = adj.size();
    
    vector<int> parent(n, -1);
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // starting from 0'th node
    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});

    // we are going to have N - 1 edge in minimum spanning tree
    for(int count = 0; count < n - 1; count++) {
        // find the minimum key in all the nodes [0, n)
        int u = pq.top().second;
        pq.pop();


        // visite the minimun key node 
        // iterate over all its adjusent nodes
        mst[u] = true;

        for (int it: adj[u]) {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false and w < key[v]) {
                parent[v] = u, key[v] = w;
                pq.push({key[v], v});
            }
        }

    }
}