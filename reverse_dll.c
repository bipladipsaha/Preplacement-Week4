// reverse_dll.c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

void reverse(struct Node** head_ref) {
    struct Node* temp = NULL;
    struct Node* current = *head_ref;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) *head_ref = temp->prev;
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
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printf("Original: "); printList(head);
    reverse(&head);
    printf("Reversed: "); printList(head);
    return 0;
}
