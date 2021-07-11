bool detect(Node* head) {
    Node* slow = head;
    Node* fast = head;
    
    while (fast and fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) {
            return true;
        }
    }
    
    return false;
}

void removeLoop(Node* head) {
    if (detect(head)) {
        Node* slow = head;
        Node* fast = head;
        
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow->next == head) {
                slow->next = nullptr;
                return;
            }
            
            if (slow == fast) {
                break;
            }
        }
        
        slow = head;
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        fast->next = nullptr;
    }
}