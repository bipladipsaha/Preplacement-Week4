// sorted_insert_cll.c  -- insert into a sorted circular linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void sortedInsert(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }
    struct Node* current = *head_ref;
    // If new node should be before head
    if (data <= (*head_ref)->data) {
        while (current->next != *head_ref) current = current->next;
        current->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    // locate node after which to insert
    while (current->next != *head_ref && current->next->data < data) current = current->next;
    new_node->next = current->next;
    current->next = new_node;
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
    sortedInsert(&head, 30);
    sortedInsert(&head, 10);
    sortedInsert(&head, 20);
    sortedInsert(&head, 25);
    printList(head); // should print sorted order: 10 20 25 30
    return 0;
}
