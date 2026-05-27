class Solution {
public:

    string encode(vector<string>& strs) {
        string returner;
        for (string str : strs) {
            returner += str + "-";
        }
        return returner;
    }

    vector<string> decode(string s) {
        string word = "";
        vector<string> returner;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '-') {
                word += s[i];
            } else {
                returner.push_back(word);
                word = "";
            }
        }
        return returner;
    }
};
