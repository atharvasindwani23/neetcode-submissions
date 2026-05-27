class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<string, vector<string>> anagrams;
        for (string str : strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            anagrams[copy].push_back(str);
        }
        vector<vector<string>> returner;
        for (auto x = anagrams.begin(); x != anagrams.end(); x++) {
            vector<string> copier;
            for (string str : x->second) {
                copier.push_back(str);
            }
            returner.push_back(copier);
        }
        return returner;
    }


    //definiton of an anagram are two strings having the same length and having the same frequency of each letter
};
