class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def is_circular(head):
    if head is None:
        return False
    temp = head.next
    while temp is not None and temp != head:
        temp = temp.next
    return temp == head

head = Node(1)
second = Node(2)
third = Node(3)
head.next = second
second.next = third
third.next = head

print(is_circular(head))

head2 = Node(1)
second2 = Node(2)
third2 = Node(3)
head2.next = second2
second2.next = third2
third2.next = None

print(is_circular(head2))
