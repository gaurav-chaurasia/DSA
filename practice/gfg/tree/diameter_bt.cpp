struct node {
    int data;
    node* left;
    node* right;
};


// methode 1
// in this problem you are given a tree and 
// you are asked to find out the diameter of the tree
int height(node* root) {
    if (root == nullptr) return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    
    return 1 + max(lh, rh);
}

int diameter(node* root) {
    if (root == nullptr) return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    int ld = diameter(root->left);
    int rd = diameter(root->right);

    return max(max(ld, rd), 1 + lh + rh);
}


// methode 2
// IMPIMPIMPIMP
int diameter_util(node* root, int* res) {
    if (root == nullptr) return 0;

    int l = diameter_util(root->left, res);
    int r = diameter_util(root->right, res);

    *res = max(res, 1 + l + r);

    return 1 + max(l, r);
}

int diameter(node* root) {
    int res = INT_MIN;
    int dump = diameter_util(root, &res);
    return res;
}