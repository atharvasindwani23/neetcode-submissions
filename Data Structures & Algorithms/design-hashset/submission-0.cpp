class MyHashSet {
public:
    unordered_map<int,bool> present;
    MyHashSet() {
        
    }
    
    void add(int key) {
        present[key] = true;
    }
    
    void remove(int key) {
        present.erase(key);
    }
    
    bool contains(int key) {
        return (present[key] == true);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */