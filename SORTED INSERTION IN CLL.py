class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    def sorted_insert(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            new_node.next = new_node
            return

        current = self.head
        if data <= self.head.data:
            while current.next != self.head:
                current = current.next
            current.next = new_node
            new_node.next = self.head
            self.head = new_node
            return

        while current.next != self.head and current.next.data < data:
            current = current.next

        new_node.next = current.next
        current.next = new_node

    def print_list(self):
        if self.head is None:
            print("List is empty.")
            return
        temp = self.head
        while True:
            print(temp.data, end=" -> ")
            temp = temp.next
            if temp == self.head:
                break
        print("(head)")

cll = CircularLinkedList()
cll.sorted_insert(10)
cll.sorted_insert(5)
cll.sorted_insert(20)
cll.sorted_insert(15)
cll.sorted_insert(2)

cll.print_list()
