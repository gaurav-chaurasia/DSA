int height_of_binary_tree(node* root) {
    if (root == nullptr) return 0;

    int height_left = height_of_binary_tree(root->left);
    int height_right = height_of_binary_tree(root->right);

    return 1 + max(height_left, height_right);
}