struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// explanations
// https://media.geeksforgeeks.org/wp-content/cdn-uploads/RGIF2.gif
Node* reverse_linked_list_iterative(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;

        // shifting pointers
        prev = curr;
        curr = next;
    }

    // prev would be pointing last element i.e. new head 
    return prev;
}

Node* reverse_linked_list_recursive(Node* head) {
    if (head == nullptr or head->next == nullptr) {
        return head;
    }

    //below we get rest of the list reversed 
    // and just adjust a few links
    Node* rest = reverse_linked_list_recursive(head->next);

    head->next->next = head;
    head->next = nullptr;

    return rest;
}