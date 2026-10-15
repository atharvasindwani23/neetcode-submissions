class LRUCache:

    class Node:
        def __init__(self, key: int, value: int):
            self.value = value
            self.key = key
            self.next = None
            self.prev = None

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.head = self.Node(-1, -1)
        self.tail = self.Node(-1, -1)

        self.head.next = self.tail
        self.tail.prev = self.head

        self.keyToNode = {}

    def get(self, key: int) -> int:
        if key not in self.keyToNode:
            return -1

        node = self.keyToNode[key]
        self.moveNode(node)
        return node.value

    def moveNode(self, node: Node):
        self.deleteNode(node)
        self.addNode(node)

    def deleteNode(self, node: Node):
        previous = node.prev
        ahead = node.next

        previous.next = ahead
        ahead.prev = previous

    def addNode(self, node: Node):
        previous = self.tail.prev

        previous.next = node
        node.prev = previous
        node.next = self.tail
        self.tail.prev = node

    def put(self, key: int, value: int) -> None:
        if key in self.keyToNode:
            node = self.keyToNode[key]
            node.value = value
            self.moveNode(node)
            return

        if len(self.keyToNode) == self.capacity:
            temp = self.head.next
            self.deleteNode(temp)
            del self.keyToNode[temp.key]

        node = self.Node(key, value)
        self.keyToNode[key] = node
        self.addNode(node)