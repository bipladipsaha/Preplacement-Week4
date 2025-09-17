class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    def create(self, n):
        if n <= 0:
            return
        self.head = Node(1)
        temp = self.head
        for i in range(2, n + 1):
            temp.next = Node(i)
            temp = temp.next
        temp.next = self.head 

    def josephus(self, k):
        if self.head is None or k <= 0:
            return None

        temp = self.head
        prev = None

        while temp.next != temp:
            for _ in range(k - 1):
                prev = temp
                temp = temp.next
            print(f"Removing: {temp.data}")
            prev.next = temp.next
            temp = prev.next

        self.head = temp
        return temp.data

n = 7
k = 3

cll = CircularLinkedList()
cll.create(n)
survivor = cll.josephus(k)
print(f"The survivor is person {survivor}")
