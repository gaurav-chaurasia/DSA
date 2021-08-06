// struct node {
//     int data;
//     node* left;
//     node* right;

//     node(int x) {
//         data = x;
//         left = nullptr;
//         right = nullptr;
//     }
// }

vector<int> left_view_binary_tree(node* root) {
    unordered_map<int, bool> mp;
    queue<pari<node*, int>> q;
    vector<int> ans;

    if (root == nullptr) 
        return ans;
    
    q.push({root, 0});

    while (!q.empty()) {
        int n = q.size();

        while(n--) {
            int level = q.front().second;
            int data = q.front().first->data;
            node *left = q.front().first->left;
            node *right = q.front().first->right;
            q.pop();

            if (mp.find(level) == mp.end()) {
                mp[level] = true;
                ans.push_back(data);
            }

            if (left != nullptr) 
                q.push({left, level + 1});

            if (right != nullptr) 
                q.push({right, level + 1});
        }
    }

    return ans;
}