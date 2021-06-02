// find intersaction of a Y shaped linkedlist
struct node {
    int data;
    node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

int get_linkedlist_length(node* head) {
    int count = 0;
    while (head != NULL) {
        head = head->next;
        count++;
    }

    return count;
}

int find_intersaction(node* h1, node* h2) {
        // Your Code Here
    int len1 = get_linkedlist_length(h1);
    int len2 = get_linkedlist_length(h2);
    
    if (h1 == h2) {
        Node* prev = h1;
        while (h1 == h2 and h1 != NULL and h2 != NULL) {
            prev = h1;
            h1 = h1->next;
            h2 = h2->next;
        }
        
        return prev->data;
    }
    else {
        int len = abs(len1 -len2);
        if (len1 > len2) {
            while(len--) {
                h1 = h1->next;
            }
        }
        else {
            while(len--) {
                h2 = h2->next;
            }
        }
        
        while (h1 != h2) {
            h1 = h1->next;
            h2 = h2->next;
        }
        
        return h1->data;
    }
}
