// intersection_y.c  -- Find intersection point of Y-shaped linked lists
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int getCount(struct Node* head) {
    int count = 0;
    while (head) { count++; head = head->next; }
    return count;
}

struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d = abs(c1 - c2);
    struct Node* longer = c1 > c2 ? head1 : head2;
    struct Node* shorter = c1 > c2 ? head2 : head1;
    for (int i = 0; i < d; i++) longer = longer->next;
    while (longer && shorter) {
        if (longer == shorter) return longer;
        longer = longer->next;
        shorter = shorter->next;
    }
    return NULL;
}

void push(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int main() {
    // create two lists that intersect
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    push(&head1, 3); push(&head1, 2); push(&head1, 1); // 1->2->3
    push(&head2, 9); push(&head2, 8); // 8->9
    // create common part 7->6
    struct Node* common = NULL;
    push(&common, 6); push(&common, 7); // 7->6
    // attach common to both lists' tails
    struct Node* t = head1; while (t->next) t = t->next; t->next = common;
    t = head2; while (t->next) t = t->next; t->next = common;
    struct Node* inter = getIntersectionNode(head1, head2);
    if (inter) printf("Intersection at node with data = %d\n", inter->data);
    else printf("No intersection\n");
    return 0;
}
