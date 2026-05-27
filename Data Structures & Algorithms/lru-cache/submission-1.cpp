class LRUCache {

private:
    struct Node {
    
    int key;
    int value;
    Node* next;
    Node* prev;
    Node (int k, int v) {
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }
    };

    Node* head;
    Node* tail;
    int capacity_;

    std::map<int, Node*> keyToNode;


    void deleteNode(Node* curr) {
        Node* previous = curr->prev;
        Node* after = curr->next;
        previous->next = after;
        after->prev = previous;
    }
    void moveToEnd(Node* curr) {
        Node* previous = tail->prev;
        Node* after = tail;
        previous->next = curr;
        curr->prev = previous;
        curr->next = tail;
        tail->prev = curr;
    }


public:
//we will use a map to store key value pairs, where our key represents a Node adress to the LRU cache
// we will use a linked list and it's head and tail pointers to create a powerful system of storing nodes
//
 
    LRUCache(int capacity) {
        capacity_ = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (keyToNode.count(key)) {
            Node* curr = keyToNode[key];
            deleteNode(curr);
            moveToEnd(curr);
            return keyToNode[key]->value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (keyToNode.count(key)) {
            Node* curr = keyToNode[key];
            deleteNode(curr);
            curr->value = value;
            moveToEnd(curr);
        } else {
            if (keyToNode.size() == capacity_) {
                keyToNode.erase(head->next->key);
                deleteNode(head->next);
            }
                Node* node = new Node(key, value);
                keyToNode[key] = node;
                moveToEnd(node);
        }
    }
};
