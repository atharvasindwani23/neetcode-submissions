class Solution {
public:
    bool isPalindrome(string s) {
        //convert everything into lower case.
        //use two pointers.
        //converge
        //if everything same, yay
        string str;
        for (char ch : s) {
            if (isalpha(ch) || isdigit(ch)) {
                str += tolower(ch);
            } 
        }
        int l = 0;
        int r = str.size() - 1;

        while (l < r) {
            if (str[l] != str[r]) {
                cout << str[l] << endl;
                return false;
            }
            l++;
            r--;
        }
        return true; 
    }
};
