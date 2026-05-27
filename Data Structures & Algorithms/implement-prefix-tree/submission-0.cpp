class PrefixTree {
public:
    std::map<string, bool> trie;
    PrefixTree() {

    }
    
    void insert(string word) {
        trie[word] = true;
    }
    
    bool search(string word) {
        return trie[word];
    }
    
    bool startsWith(string prefix) {
        for (auto x = trie.begin(); x != trie.end(); x++) {
            if (prefixes(x->first, prefix)) {
                return true;
            }
        }
        return false;
    }

    bool prefixes(string str, string st) {
    //if st is a prefix of str -> O(n)
    if (st.size() > str.size()) {
        return false;
    }
    for (int i = 0;  i < st.size(); i++) {
        if (st[i] != str[i]) {
            return false;
        }
    }
    return true;
   }
};
