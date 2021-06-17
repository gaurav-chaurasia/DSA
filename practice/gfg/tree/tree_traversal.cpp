struct node {
    int data;
    node* left;
    node* right;
    node (int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};


void in_order(node* root) {
    if (root == nullptr) return;

    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

void pre_order(node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(node* root) {
    if (root == nullptr) return;

    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
}

void level_order(node* root) {
    if (root == nullptr) return;

    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        int item = q.front(); q.pop();

        cout << item->data << endl;

        if(item->left) q.push(item->left);
        if(item->right) q.push(item->right);
    }
}