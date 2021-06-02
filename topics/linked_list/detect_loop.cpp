struct node {
    int data;
    node* next;

    node(int x) {
        data = x;
        node = NULL;
    }
};

// this is called Floyd's loop detection algorithm
bool detect_loop(node* head) {
    node* slow = head;
    node* fast = head;

    while (slow and fast and fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) 
            return true;
    }
    return false;
}
