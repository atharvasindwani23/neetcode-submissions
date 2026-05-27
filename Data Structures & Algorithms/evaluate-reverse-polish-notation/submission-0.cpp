class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> token;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int first = token.top();
                token.pop();
                int second = token.top();
                token.pop();
                token.push(first + second);
                continue;
            }
            if (tokens[i] == "*") {
                int first = token.top();
                token.pop();
                int second = token.top();
                token.pop();
                token.push(first * second);
                continue;
            }
            if (tokens[i] == "-") {
                int first = token.top();
                token.pop();
                int second = token.top();
                token.pop();
                token.push(second - first);
                continue;
            }
            if (tokens[i] == "/") {
                int first = token.top();
                token.pop();
                int second = token.top();
                token.pop();
                token.push(second / first);
                continue;
            }
            token.push(std::stoi(tokens[i]));
        }
        return token.top();
    }
};
