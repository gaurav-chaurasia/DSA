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

// method 1
// recursive
// O(h) {h is height of the tree}
// O(1) constant space complexity if we ignore recursion stack 
node* LCA(node* root, int n1, int n2) {
    if (root == nullptr) 
        return root;

    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);

    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);

    return root;
}

// method 2
// iterative
// O(h) {h is height of the tree}
// O(1) constant space complexity

node* LCA(node* root, int n1, int n2) {
    while(root != nullptr) {
        if (root->data > n1 && root->data > n2)
            root = root->left;
        else if (root->data < n1 && root->data < n2)
            root = root->right;
        else break;
    }

    return root;
}