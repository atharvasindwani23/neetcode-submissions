class Solution {
public:
    bool isAnagram(string s, string t) {
        //sort strings and check if they're the same.
        //use a map and check if the frequency of the characters is the same in each of the cases
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
