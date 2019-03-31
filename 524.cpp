// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/
/*
Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

Example 1:

Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

Output:
"apple"
Example 2:

Input:
s = "abpcplea", d = ["a","b","c"]

Output:
"a"
*/

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {

        string currMax = "";
        for (string i : d) {
            if (isPossible(s, i)) {
                if (currMax == "" || i.length() > currMax.length() ||
                    (i.length() == currMax.length() && currMax > i))
                    currMax = i;
            }
        }
        return currMax;
    }

    bool isPossible(string s, string t) {
        // check if deleting part of s gives t
        int i = 0;
        int j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return j == t.length();
    }
};

/*
Runtime: 96 ms, faster than 44.83% of C++ online submissions for Longest Word in Dictionary through Deleting.
Memory Usage: 26.2 MB, less than 22.97% of C++ online submissions for Longest Word in Dictionary through Deleting.
*/
