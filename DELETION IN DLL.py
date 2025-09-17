class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node
        new_node.prev = temp

    def delete_node(self, key):
        temp = self.head

        if temp is None:
            print("List is empty, nothing to delete.")
            return

        if temp.data == key:
            self.head = temp.next
            if self.head:
                self.head.prev = None
            temp = None
            return

        while temp and temp.data != key:
            temp = temp.next

        if temp is None:
            print(f"Node with data {key} not found.")
            return

        if temp.next:
            temp.next.prev = temp.prev

        if temp.prev:
            temp.prev.next = temp.next

        temp = None

    def print_list(self):
        temp = self.head
        while temp:
            print(temp.data, end=" <-> " if temp.next else "")
            temp = temp.next
        print()
dll = DoublyLinkedList()
dll.insert_at_end(10)
dll.insert_at_end(20)
dll.insert_at_end(30)
dll.insert_at_end(40)

print("Original list:")
dll.print_list() 

dll.delete_node(20)
print("After deleting 20:")
dll.print_list()  

dll.delete_node(10)
print("After deleting 10 (head):")
dll.print_list()

dll.delete_node(50)  
