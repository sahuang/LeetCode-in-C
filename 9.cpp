// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        long long int ans = 0;
        int temp = x;
        while (temp) {
            ans = ans * 10 + temp % 10;
            temp /= 10;
        }
        return x == ans;
    }
};

/*
Runtime: 32 ms, faster than 99.79% of C++ online submissions for Palindrome Number.
Memory Usage: 8.1 MB, less than 99.67% of C++ online submissions for Palindrome Number.
*/