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

// in order traversal in tree recursive implimentation
void in_order(node* root) {
    if (root == nullptr) return;

    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

// in order traversal in tree iterative implimentation
void in_order_iterative(node* root) {
    if (root == nullptr) return;

    stack<node* root> st;
    node* curr = root;
    while (!st.empty() || curr != nullptr) {
        if (temp != nullptr) {
            st.push(curr);
            curr = curr->left;
        }
        else {
            curr = st.top();
            st.pop();

            cout << curr->data << " ";
            curr = curr->right;
        }
    }
}

// pre order traversal in tree recursive implimentation
void pre_order(node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}

// pre order traversal in tree iterative implimentation
void pre_order_iterative(node* root) {
    if (root == nullptr) return;

    stack<node*> st;
    st.push(root);
    while (!st.empty()) {
        node* curr = st.top();
        st.pop();

        cout << curr -> data << " ";

        if (curr->left) st.push(curr->left);
        if (curr->right) st.push(curr->right);
    }
}

// post order traversal in tree recursive implimentation
void post_order(node* root) {
    if (root == nullptr) return;

    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
}


void post_order_iterative(node* root) {
    if (root == nullptr) return;

    stack<node *> st;
    stack<int> output;
    st.push(root);

    while (!st.empty()) {
        node* curr = st.top();
        st.pop();
        output.push(curr->data);

        if (curr->left) st.push(curr->left);
        if (curr->right) st.push(curr->right);
    }

    while(!output.empty()) {
        cout << output.top() << " ";
        output.pop();
    }
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