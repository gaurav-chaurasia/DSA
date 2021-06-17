// methode 1
void get_in_order(Node* root, queue<Node*> &q) {
    if(root == nullptr) return;
    
    get_in_order(root->left, q);
    q.push(root);
    get_in_order(root->right, q);
}

Node* binary_tree_to_doubly_linked_list(Node* root) {
    if (root == nullptr) return root;
    
    queue<Node*> q;
    get_in_order(root, q);
    
    Node* ans = q.front();
    Node* prev = nullptr;
    while(!q.empty()) {
        Node* curr = q.front(); q.pop();
        Node* next = q.empty() ? nullptr : q.front();
        
        curr->right = next;
        curr->left = prev;
        
        prev = curr;
    }
    
    return ans;
}



// methode 2
