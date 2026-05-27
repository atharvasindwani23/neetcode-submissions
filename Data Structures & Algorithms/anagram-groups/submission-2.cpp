class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> anagrams;
        for (string str : strs) {
            string x = str;
            sort(x.begin(), x.end());
            anagrams[x].push_back(str);
        }
        vector<vector<string>> res;
        for (auto x = anagrams.begin(); x != anagrams.end(); x++) {
            res.push_back(x->second);
        }
        return res;
    }

    //key is the sorted word, values are all words which resemble that while getting sorted
};
