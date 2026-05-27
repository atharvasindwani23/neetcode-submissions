class LRUCache {

private:

struct ListNode {

int key = 0;
int value = 0;
ListNode* next;
ListNode* prev;

ListNode(int k, int v) {
    key = k;
    value = v;
}
};

int capacity_ = 0;
ListNode* head;
ListNode* tail;
unordered_map<int, ListNode*> lru;

//deletion, additon to the end

void deleteNode(ListNode* curr) {
    ListNode* before = curr->prev;
    ListNode* after = curr->next;
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
        head =  new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
        capacity_ = capacity;
    }
    
    int get(int key) {
        if (lru.count(key)) {
            moveToTail(lru[key]);
            return lru[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (lru.count(key)) {
            ListNode* node = lru[key];
            node->value = value;
            moveToTail(node);
            return;
        }
        if (capacity_ == lru.size()) {
            ListNode* toDelete = head->next;
            deleteNode(head->next);
            lru.erase(toDelete->key);
            delete toDelete;
        }
        ListNode* newNode = new ListNode(key, value);
        addToTail(newNode);
        lru[key] = newNode;
    }
};
