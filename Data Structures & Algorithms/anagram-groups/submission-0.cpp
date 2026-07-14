class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> anagrams_;

        for (string str : strs) {
            string x = str;
            sort(x.begin(), x.end());
            anagrams_[x].push_back(str);
        }
        for (auto x = anagrams_.begin(); x != anagrams_.end(); x++)  {
            result.push_back(x->second);
        }
        return result;
    }
};
