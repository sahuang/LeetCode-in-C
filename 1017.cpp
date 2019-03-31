// https://leetcode.com/problems/convert-to-base-2/
/*
Given a number N, return a string consisting of "0"s and "1"s that represents its value in base -2 (negative two).

The returned string must have no leading zeroes, unless the string is "0".



Example 1:

Input: 2
Output: "110"
Explantion: (-2) ^ 2 + (-2) ^ 1 = 2
Example 2:

Input: 3
Output: "111"
Explantion: (-2) ^ 2 + (-2) ^ 1 + (-2) ^ 0 = 3
Example 3:

Input: 4
Output: "100"
Explantion: (-2) ^ 2 = 4
*/

class Solution {
public:
    string baseNeg2(int N) {
        if (N == 0) return "0";
        // first convert N to binary, in opposite order
        string s = toBin(N);
        int carry = 0;
        for (int i = 0; i < s.length(); i++) {
            if (carry == 0 && i % 2 == 1 && s[i] == '1') {
                carry = 1;
            } else if (carry == 1) {
                if (s[i] == '1') s[i] = '0';
                else {
                    if (i % 2 == 0) carry = 0;
                    s[i] = '1';
                }
            }
        }
        if (carry && s.length() % 2) s += "11";
        else if (carry && s.length() % 2 == 0) s += "1";
        reverse(s.begin(), s.end());
        return s;
    }

    string toBin(int N) {
        string ans = "";
        while (N) {
            ans += to_string(N % 2);
            N /= 2;
        }
        return ans;
    }
};

/*
Runtime: 8 ms, faster than 100.00% of C++ online submissions for Convert to Base -2.
Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Convert to Base -2.
*/
