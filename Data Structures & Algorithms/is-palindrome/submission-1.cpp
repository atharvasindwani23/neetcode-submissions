class Solution {
public:
    bool isPalindrome(string s) {
     string copy = "";
     for (char ch : s) {
        if (isalpha(ch) || isdigit(ch)) {
        copy += tolower(ch);
        }
     }
    string compare = "";
    for (int i  = copy.size() - 1; i >= 0; i--) {
        if (isalpha(copy[i]) || isdigit(copy[i])) {
        compare += copy[i];
        }
    }
    std::cout << compare << std:: endl;
        return (copy == compare);
    }
};
