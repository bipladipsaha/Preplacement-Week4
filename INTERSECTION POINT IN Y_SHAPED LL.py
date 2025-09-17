class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def get_length(head):
    count = 0
    while head:
        count += 1
        head = head.next
    return count

def get_intersection(head1, head2):
    len1 = get_length(head1)
    len2 = get_length(head2)

    diff = abs(len1 - len2)
    if len1 > len2:
        for _ in range(diff):
            head1 = head1.next
    else:
        for _ in range(diff):
            head2 = head2.next

    while head1 and head2:
        if head1 is head2:
            return head1.data
        head1 = head1.next
        head2 = head2.next

    return None

common = Node(3)
common.next = Node(4)
common.next.next = Node(5)

head1 = Node(1)
head1.next = Node(2)
head1.next.next = common

head2 = Node(6)
head2.next = Node(7)
head2.next.next = common

result = get_intersection(head1, head2)

if result:
    print("Intersection point data:", result)
else:
    print("No intersection found.")
