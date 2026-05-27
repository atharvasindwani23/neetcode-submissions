class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int ptr1 = 0;
        int ptr2 = 0;
        string res = "";
        while (ptr1 < word1.size() && ptr2 < word2.size()) {
            res += word1[ptr1];
            res += word2[ptr1];
            ptr1++;
            ptr2++;
        }
        if (ptr1 == word1.size()) {
            res += word2.substr(ptr2);
        } else {
            res+= word1.substr(ptr1);
        }
    return res;
    }
};