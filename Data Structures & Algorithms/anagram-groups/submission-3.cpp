class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for (string str : strs) {
            string word = str;
            sort(word.begin(), word.end());
            anagrams[word].push_back(str);
        }
        vector<vector<string>> result;
        for (auto x = anagrams.begin(); x != anagrams.end(); x++) {
            result.push_back(x->second);
        }
        return result;
    }
};
