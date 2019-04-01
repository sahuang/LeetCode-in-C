// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        if (!s.length()) return true;
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') st.push(c);
            else {
                if (st.empty()) return false;
                char t = st.top();
                if ((c == '}' && t == '{') || (c == ']' && t == '[') 
                    || (c == ')' && t == '(')){
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

/*
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Valid Parentheses.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Valid Parentheses.
*/
