// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 0) return;
        int zeroIndex = 0;
        int curr = 0;
        while (curr < nums.size()) {
            if (nums[curr] != 0) curr++;
            else break;
        }
        if (curr == nums.size()) return;
        zeroIndex = curr;
        curr++;
        while (curr < nums.size()) {
            if (nums[curr] == 0) {
                curr++;
            }
            else {
                swap(nums[curr++], nums[zeroIndex++]);
            }
        }
        return;
    }
};

/*
Runtime: 16 ms, faster than 99.30% of C++ online submissions for Move Zeroes.
Memory Usage: 9.4 MB, less than 92.95% of C++ online submissions for Move Zeroes.
*/
