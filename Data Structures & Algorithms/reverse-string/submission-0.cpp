class Solution {
public:
    void reverseString(vector<char>& s) {
        int lower = 0;
        int upper = s.size() - 1;
        while (lower < upper) {
            swap(s[lower], s[upper]);
            lower++;
            upper--;
        }
    }
};