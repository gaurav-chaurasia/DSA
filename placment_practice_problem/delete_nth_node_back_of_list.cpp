node* solve(node* head, int n) {
    node* start = new node(0);
    start->next = head;
    node* fast = start;
    node* slow = start;

    for (int i = 0; i < n; i++) {
        if (fast->next == nullptr) {
            // n is larger than the length of the list
            return nullptr;
        }
        fast = fast->next;
    }

    while (fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;

    return start->next;
}