struct node {
    int data;
    node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
};


node* reverse_in_group(node* head, int k) {
    node* curr = head;
    node* next = NULL;
    node* prev = NULL;
    int count = 0;

    while (curr != NULL and count < k) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL) {
        head->next = reverse_in_group(next, k);
    }

    return prev;
}