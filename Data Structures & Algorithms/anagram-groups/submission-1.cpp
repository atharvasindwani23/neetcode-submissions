class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> res;
        for (string str : strs) {
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            res[sorted].push_back(str);
        }
        vector<vector<string>> returner;
        for (auto x = res.begin(); x != res.end(); x++) {
            returner.push_back(x->second);
        }
        return returner;
    }
};
