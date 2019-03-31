// https://leetcode.com/problems/valid-anagram/
/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (!s.length() && !t.length()) return true;
        if (!s.length() || !t.length()) return false;
        if (s.length() != t.length()) return false;

        /*
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != t[i]) return false;
        }
        */

        int table[26] = {0};
        for (int i = 0; i < s.length(); i++) table[s[i] - 'a']++;
        for (int i = 0; i < t.length(); i++) {
            table[t[i] - 'a']--;
            if (table[t[i] - 'a'] < 0) return false;
        }
        return true;
    }
};

/*
Runtime: 12 ms, faster than 98.22% of C++ online submissions for Valid Anagram.
Memory Usage: 9.4 MB, less than 9.58% of C++ online submissions for Valid Anagram.
*/
