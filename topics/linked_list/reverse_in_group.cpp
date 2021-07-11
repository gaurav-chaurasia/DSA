struct node {
    int data;
    node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
};


node* reverse_in_group(node* head, int k) {
    if (head == nullptr) return head;

    node *prev = nullptr;
    node *curr = head;
    node *next = head;
    int count = k;

    while (count-- and curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head->next = reverse(curr, k);

    return prev;
}