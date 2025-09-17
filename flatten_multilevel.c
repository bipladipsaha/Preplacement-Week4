// flatten_multilevel.c  -- Flatten a multi-level linked list (each node may have child pointer)
// We'll implement a simple version: Node has next and child. Flatten by depth-first merging.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* child;
};

struct Node* createNode(int d) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = d; n->next = n->child = NULL; return n;
}

struct Node* flatten(struct Node* head) {
    if (!head) return NULL;
    struct Node* tail = head;
    // find initial tail of first level
    while (tail->next) tail = tail->next;
    struct Node* cur = head;
    while (cur) {
        if (cur->child) {
            tail->next = cur->child;
            // update new tail
            struct Node* t = cur->child;
            while (t->next) t = t->next;
            tail = t;
            cur->child = NULL;
        }
        cur = cur->next;
    }
    return head;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Build a sample multilevel list:
    // 1 - 2 - 3 - 4
    //     |   |
    //     7   8 - 9
    struct Node* n1 = createNode(1);
    struct Node* n2 = createNode(2);
    struct Node* n3 = createNode(3);
    struct Node* n4 = createNode(4);
    n1->next = n2; n2->next = n3; n3->next = n4;
    n2->child = createNode(7);
    n3->child = createNode(8);
    n3->child->next = createNode(9);
    printf("Before flatten (level-order print not shown). After flatten: ");
    struct Node* head = flatten(n1);
    printList(head);
    return 0;
}
