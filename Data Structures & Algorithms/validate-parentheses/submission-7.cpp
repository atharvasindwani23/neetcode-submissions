class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.size(); i++) {
            std::cout << i;
            if (!st.empty() && st.top() == '(' && s[i] == ')') {
                st.pop();
            } else if (!st.empty() && st.top() == '[' && s[i] == ']') {
                st.pop();
            } else if (!st.empty() && st.top() == '{' && s[i] == '}') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};
