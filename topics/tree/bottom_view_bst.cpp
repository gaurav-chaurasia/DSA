
struct node {
    int data;
    node* left;
    node* right;

    node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};


void find_horizontal_distance(node* root, int height, unordered_map<node*, int> &hori_dist) {
    if (root == nullptr) return;

    hori_dist[root] = height;

    find_horizontal_distance(root->left, height - 1, hori_dist);
    find_horizontal_distance(root->right, height + 1, hori_dist);
}

vector<int> bottom_view(node* root) {
    map<int, int> mp;
    queue<node*> q;
    vector<int> ans;

    if (root == nullptr) return ans;

    // to store horizontal distance of each node
    unordered_map<node*, int> hori_dist;
    find_horizontal_distance(root, 1e5 + 1, hori_dist);

    q.push(root);

    while (!q.empty()) {
        node* curr = q.front(); q.pop();

        mp[hori_dist[curr]] = curr->data;

        if (root->left != nullptr) q.push(root->left);
        if (root->right != nullptr) q.push(root->right);
    }

    for(auto it = mp.begin(); it != mp.end(); it++)
        cout << it->second << " ";
}