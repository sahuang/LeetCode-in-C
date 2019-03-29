// https://leetcode.com/problems/largest-number/
/*
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {

        vector<string> num;
        for (auto i : nums) num.push_back(to_string(i));

        auto sortRuleLambda = []
            (const string& s1, const string& s2) -> bool {
            return s1 + s2 > s2 + s1;
        };
        sort(num.begin(), num.end(), sortRuleLambda);
        if (num[0][0] == '0') return "0";
        string ans = "";
        for (auto i : num)
            ans += i;
        return ans;
    }
};

/*
Runtime: 8 ms, faster than 99.93% of C++ online submissions for Largest Number.
Memory Usage: 9.3 MB, less than 98.95% of C++ online submissions for Largest Number.
*/
