class LRUCache {

private:
    struct Node {
    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }     
    };

    Node* head;
    Node* tail;
    int capacity_;
    std::map<int, Node*> keyToNode;

    void moveToEnd(Node* curr) {
        deleteNode(curr);
        insertToEnd(curr);
    }
    void deleteNode(Node* curr) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    void insertToEnd(Node* curr) {
        //1->2->3->tail => 1->2->3->4->tail
        Node* back = tail->prev;
        back->next = curr;
        curr->next = tail;
        tail->prev = curr;
        curr->prev = back;
    }

public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (keyToNode.find(key) == keyToNode.end()) {
            return -1;
        }
        Node* node = keyToNode[key];
        moveToEnd(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (keyToNode.find(key) == keyToNode.end()) {
            if (keyToNode.size() == capacity_) {
                Node* lru = head->next;
                keyToNode.erase(lru->key);
                deleteNode(lru);
                delete lru;
            }
            Node* insert = new Node(key,value);
            keyToNode[key] = insert;
            insertToEnd(insert);
        } else {
            Node* node = keyToNode[key];
            node->value = value;
            moveToEnd(node);
        }
    }

    // least recently used => something which we havent used in a long time [get, put both count as a use]
    //most recently used => [the one which we just used]
    //ordering [linked list]
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */