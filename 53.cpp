// https://leetcode.com/problems/maximum-subarray/
/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        if (!nums.size()) return 0;
        int currMax = nums[0];
        int currSum = 0;
        for (int i : nums) {
            currSum += i;
            currMax = max(currMax, currSum);
            if (currSum < 0) currSum = 0;
        }
        return currMax;
    }
};

/*
Runtime: 8 ms, faster than 99.48% of C++ online submissions for Maximum Subarray.
Memory Usage: 9.3 MB, less than 99.63% of C++ online submissions for Maximum Subarray.
*/
