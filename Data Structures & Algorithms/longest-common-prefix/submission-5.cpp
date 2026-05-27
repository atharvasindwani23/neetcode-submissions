class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int min = INT_MAX;
        string minStr = "";
        for (string str : strs) {
            if (str.size() < min) {
                min = str.size();
                minStr = str;
            }
        }
        for (int i = 0; i < minStr.size(); i++) {
           if (helper(strs, i)) {
              cout << "meow?" << endl;
             res += minStr[i];
           } else {
            return res;
           }
        }
        return res;
    }

    bool helper(vector<string>& strs, int idx) {
        char ch = strs[0][idx];
        cout << ch << endl;
        for (string str : strs) {
            if (str[idx] != ch) {
                return false;
            }
        }
        cout << "here right?" << endl;
        return true;
    }

    //LCP for every sequence of strings we have
};