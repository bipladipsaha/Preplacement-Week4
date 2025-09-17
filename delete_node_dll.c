// delete_node_dll.c
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
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL) (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL) return;
    if (*head_ref == del) *head_ref = del->next;
    if (del->next != NULL) del->next->prev = del->prev;
    if (del->prev != NULL) del->prev->next = del->next;
    free(del);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node* search(struct Node* head, int key) {
    while (head) {
        if (head->data == key) return head;
        head = head->next;
    }
    return NULL;
}

int main() {
    struct Node* head = NULL;
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printf("Original list: "); printList(head);
    struct Node* node = search(head, 2);
    deleteNode(&head, node);
    printf("After deleting 2: "); printList(head);
    return 0;
}
