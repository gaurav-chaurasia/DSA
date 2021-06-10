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

class GKC {

public:
    void diameter_of_binary_tree(node* root, int &res) {
        if (root == nullptr) return 0;

        int l = diameter_of_binary_tree(root->left, res);
        int r = diameter_of_binary_tree(root->right, res);

        int temp = 1 + max(l, r);
        int ans = max(temp, 1 + l + r);
        res = max(res, ans);
    }

};