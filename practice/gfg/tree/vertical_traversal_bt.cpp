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

void find_horizontal_dist(Node* root, int height, unordered_map<Node*, int> &hori_dist) {
    if (root == nullptr) return;
    
    hori_dist[root] = height;
    
    find_horizontal_dist(root->left, height - 1, hori_dist);
    find_horizontal_dist(root->right, height + 1, hori_dist);
}

vector<int> vertical_order(node *root) {
    vector<int> ans;
    queue<node*> q;
    map<int, vector<int>> mp;
    unordered_map<node*, int> hori_dist;
    
    find_horizontal_dist(root, 1e5 + 1, hori_dist);
    
    
    if (root == nullptr) return ans;
    
    q.push(root);
    
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            node* item = q.front(); q.pop();
            
            mp[hori_dist[item]].push_back(item->data);
            
            if (item->left != nullptr) q.push(item->left);
            if (item->right != nullptr) q.push(item->right);
        }
    }
    
    for (auto it = mp.begin(); it != mp.end(); it++) {
        for (auto i: it->second) {
            ans.push_back(i);
        }
    }
    
    return ans;
}