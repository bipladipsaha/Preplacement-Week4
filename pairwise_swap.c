// pairwise_swap.c  -- Pairwise swap nodes by data in singly linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void pairwiseSwap(struct Node* head) {
    while (head != NULL && head->next != NULL) {
        int tmp = head->data;
        head->data = head->next->data;
        head->next->data = tmp;
        head = head->next->next;
    }
}

void printList(struct Node* node) {
    while (node) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    for (int i = 5; i >= 1; --i) push(&head, i); // 1 2 3 4 5
    printf("Original: "); printList(head);
    pairwiseSwap(head);
    printf("Pairwise swapped: "); printList(head);
    return 0;
}
