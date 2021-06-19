struct node {
    int data;
    node* left;
    node* right;
};

// problem 1
// in this problem we have a tree and 
// we are supposed to find out the maximum path sum possible 
// from one leaf to another leaf
int max_path_sum_leaf_to_leaf_util(node* root, int* res) {
    if (root == nullptr) return 0;
    if (root->left && !root->right) return root->data;

    int l = max_path_sum_leaf_to_leaf_util(root->left, res);
    int r = max_path_sum_leaf_to_leaf_util(root->right, res);

    if (root->left && root->right) {
        *res = max(ans, root->data + l + r);
        return max(l, r) + root->data;
    }

    return (root->left) ? l + root->data : r + root->data; 
}
int max_path_sum_leaf_to_leaf(node* root) {
    int res = INT_MIN;
    int dump = max_path_sum_leaf_to_leaf_util(root, &res);

    if (res == INT_MIN) {
        return dump;
    }
    return res;
}




// problem 2
// in this problem we have a tree and
// we are supposed to find out the maximum path sum possible from any node to any
int max_path_sum_util(node* root, int* res) {
    if (root == nullptr) return 0;

    int l = max_path_sum_util(root->left, res);
    int r = max_path_sum_util(root->right, res);

    int temp = max(root->data, max(l, r) + root->data);
    int ans = max(*res, temp);
    *res = max(ans, l + r + root->data);

    return temp;
}

int max_path_sum(node* root) {
    int res = INT_MIN;
    int dump = max_path_sum_util(root, &res);
    return res;
}