struct node {
    int data;
    node* left;
    node* right;
};

void count_leave_util(node* root, int* count) {
    if (root == nullptr) return;

    if (!(root->left && root->right)) *count += 1;

    count_leave_util(root->left);
    count_leave_util(root->right);
}

int count_leaves_in_binary_tree(node* root) {
    if (root == nullptr) return 0;

    int count = 0;
    count_leaves_util(root, &count);

    return count;
}