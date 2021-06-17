struct node {};

// method 1
// problem statment
// in this problem you have find wheather tree is mirror image of itself
void custom_push(stack<pair<int, bool>> &st, int data, int dir) {
    if (!st.empty() && st.top().first == data && st.top.second != dir) {
        st.pop();
        return;
    }
    st.push({data, dir});
}

bool is_symmetric(node* root) {
    if (root == nullptr) return true;

    queue<node*> q; q.push(root);
    stack<pair<int, bool>> st;

    while (!q.empty()) {
        node* item = q.front(); q.pop();

        if (item->left) {
            q.push(item->left);
            custom_push(st, item->left->data, false);
        }
        if (item->right) {
            q.push(item->right);
            custom_push(st, item->left->data, true);
        }
    }
}



// method 2
// recursive approach 
bool is_mirror(node* a, node* b) {
    if (a == nullptr and b == nullptr) return true;

    if (a && b && a->data == b->data) 
        return is_mirror(a->left, b->right) && is_mirror(a->right, b->left);

    return false;
}
bool is_symmetric(node* root) {
    return is_mirro(root, root);
}