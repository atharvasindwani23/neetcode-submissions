class LRUCache {

private:

struct ListNode {

ListNode* next;
ListNode* prev;



int key = 0;
int value = 0;

ListNode(int k, int v) {
    key = k;
    value = v;
}
};

ListNode* tail;
ListNode* head;
int capacity_;
unordered_map<int, ListNode*> keyToNode;

void deleteNode(ListNode* curr) {
    ListNode* after = curr->next;
    ListNode* before = curr->prev;
    before->next = after;
    after->prev = before;
}

void addToTail(ListNode* curr) {
    ListNode* before = tail->prev;
    before->next = curr;
    curr->prev = before;
    curr->next = tail;
    tail->prev = curr;
}

void moveToTail(ListNode* curr) {
    deleteNode(curr);
    addToTail(curr);
}


public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (keyToNode.count(key)) {
            moveToTail(keyToNode[key]);
            return keyToNode[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (keyToNode.count(key)) {
            ListNode* node = keyToNode[key];
            node->value = value;
            moveToTail(node);
            return;
        }
        if (capacity_ == keyToNode.size()) {
            ListNode* evict = head->next;
            deleteNode(evict);
            keyToNode.erase(evict->key);
            delete evict;
        }
        ListNode* newNode = new ListNode(key, value);
        keyToNode[key] = newNode;
        addToTail(newNode);
    }
};
