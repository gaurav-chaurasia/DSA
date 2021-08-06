// struct node {
//     int data;
//     node* left;
//     node* right;
//     node(int x) {
//         data = x;
//         left = nullptr;
//         right = nullptr;
//     }
// };

bool is_bst_util(node* root, int min, int max) {
    if (root == nullptr) 
        return true;
    
    if (root->data < min || root->data > max)
        return false;

    return is_bst_util(root->left, min, root->data - 1) && 
            is_bst_util(root->right, root->data + 1, max);
}

bool is_bst(node* root) {
    return is_bst_util(root, INT_MIN, INT_MAX);
}