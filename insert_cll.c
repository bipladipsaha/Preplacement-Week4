// insert_cll.c  -- Insert node into Circular Linked List (insert at end)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertEnd(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }
    struct Node* temp = *head_ref;
    while (temp->next != *head_ref) temp = temp->next;
    temp->next = new_node;
    new_node->next = *head_ref;
}

void printList(struct Node* head) {
    if (head == NULL) { printf("Empty\n"); return; }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    printList(head);
    return 0;
}
