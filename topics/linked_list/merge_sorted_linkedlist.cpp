Node *sortedMerge(Node *head1, Node *head2) {
    Node *root = (head1->data <= head2->data) ? head1 : head2;
    Node *temp = root;
    Node *t1 = head1;
    Node *t2 = head2;

    t1->data <= t2->data ? t1 = t1->next : t2 = t2->next;

    while (t1 and t2) {
        if (t1->data <= t2->data) {
            temp->next = t1;
            t1 = t1->next;
        }
        else {
            temp->next = t2;
            t2 = t2->next;
        }
        temp = temp->next;
    }

    if (t1)
        temp->next = t1;
    if (t2)
        temp->next = t2;

    return root;
}