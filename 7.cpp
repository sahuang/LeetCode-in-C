// https://leetcode.com/problems/reverse-integer/
/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
public:
    int reverse(int x) {
        string y = to_string(x);
        int ans = 0;
        reverseStr(y);
        for (int i = 0; i < y.length() - 1; i++) {
            if (ans && INT_MAX / ans >= 10 && 
                INT_MAX - 10 * ans >= y[i] - '0')
                ans = ans * 10 + (y[i] - '0');
            else if (ans == 0) ans = y[i] - '0';
            else return 0;
        }
        if (y[y.length() - 1] == '-') return -ans;
        else {
            if (ans && INT_MAX / ans >= 10 && 
                INT_MAX - 10 * ans >= y[y.length() - 1] - '0')
                return ans * 10 + (y[y.length() - 1] - '0');
            else if (ans == 0) return y[y.length() - 1] - '0';
            else return 0;
        }
    }
    
    void reverseStr(string& str) { 
        int n = str.length(); 
        for (int i = 0; i < n / 2; i++) 
            swap(str[i], str[n - i - 1]); 
    } 
};
