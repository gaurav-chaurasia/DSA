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

int height_of_binary_tree(node* root) {
    if (root == nullptr) 
        return 0;
    
    int LH = height_of_binary_tree(root->left);
    int RH = height_of_binary_tree(root->right);
    
    return 1 + max(LH, RH);
}