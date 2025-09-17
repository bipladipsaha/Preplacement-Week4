// insert_begin_dll.c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void insertAtBeginning(struct Node **head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL) (*head)->prev = newNode;
    *head = newNode;
}

void printList(struct Node* node) {
    struct Node* last = NULL;
    printf("Forward: ");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\nBackward: ");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    printList(head);
    return 0;
}
