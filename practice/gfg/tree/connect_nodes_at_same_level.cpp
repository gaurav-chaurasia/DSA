void connect(Node *root) {
    queue<pair<Node*, int>> q;
    queue<pair<Node*, int>> qh;
    
    if (root == nullptr) return;
    
    q.push({root, 1});
    
    while(!q.empty()) {
        int n = q.size();
        
        while (n--) {
            Node* item = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if (item->left) q.push({item->left, level + 1});
            if (item->right) q.push({item->right, level + 1});
            
            qh.push({item, level});
        }
    }
    
    while(!qh.empty()) {
        Node* curr_item = qh.front().first;
        int curr_level = qh.front().second;
        qh.pop();
        
        if (!qh.empty()) {
            if (curr_level == qh.front().second) {
                curr_item->nextRight = qh.front().first;
            }
            else {
                curr_item->nextRight = nullptr;                    
            }
        }
        else {
            curr_item->nextRight = nullptr;
        }
    }   
}
