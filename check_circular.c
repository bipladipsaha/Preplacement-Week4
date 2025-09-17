// check_circular.c  -- Check if a singly linked list is circular
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int isCircular(struct Node* head) {
    if (head == NULL) return 1; // empty list treated as circular by some definitions; return 0 if you prefer
    struct Node* temp = head->next;
    while (temp != NULL && temp != head) temp = temp->next;
    return (temp == head);
}

void push(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int main() {
    struct Node* head = NULL;
    push(&head, 3); push(&head, 2); push(&head, 1);
    printf("Is circular? %s\n", isCircular(head) ? "Yes" : "No");
    // make it circular for test
    head->next->next->next = head;
    printf("After making circular, Is circular? %s\n", isCircular(head) ? "Yes" : "No");
    return 0;
}
