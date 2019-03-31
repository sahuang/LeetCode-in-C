// https://leetcode.com/problems/longest-substring-without-repeating-characters/
/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if (!s.length()) return 0;
        int curr = 0;
        int longest = 1;
        set<char> occur;
        for (int i = 0; i < s.length(); i++) {
            if (occur.find(s[i]) == occur.end()) {
                curr++;
                longest = max(longest, curr);
                occur.insert(s[i]);
            } else {
                // remove from front till s[i]
                int j = i - curr;
                while (s[j] != s[i]) {
                    occur.erase(s[j++]);
                    curr--;
                } 
            }
        }
        return longest;
    }
};

// accepted
