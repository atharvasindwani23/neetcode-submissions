class WordDictionary {
public:
    std::map<string, bool> ds;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        ds[word] = true;  
    }
    
    bool search(string word) {
        if (ds.find(word) != ds.end()) {
            return true;
        }
        for (auto x = ds.begin(); x != ds.end(); x++) {
            string w  = x->first;
            std::cout << w << std::endl;
            if (match(word, w)) {
                //std::cout << w << std::endl;
                return true;
            }
        }
        return false;
    }

    bool match(string str, string st) {
        if (str.size() != st.size()) {
            return false;
        }
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '.') {
                continue;
            }
            if (str[i] != st[i]) {
                return false;
            }
        }
        //std::cout << str << std::endl;
        //std::cout << st << std::endl;
        return true;
    }
};
