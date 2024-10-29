class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char& c : s) {
            if (stk.empty() && (c == ']' || c == '}' || c == ')')) return false;
            if (c == '{' || c == '(' || c == '[') {
                stk.push(c);
            } else {
                char left = stk.top();
                if ((left == '{' && c != '}') 
                || (left == '[' && c != ']') 
                || (left == '(' && c != ')')) return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};