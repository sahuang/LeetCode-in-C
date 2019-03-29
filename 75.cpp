// https://leetcode.com/problems/sort-colors/
/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int l = 0;
        int r = nums.size() - 1;
        for (int i = 0; i <= r; i++) {
            if (nums[i] == 0) swap(nums[l++], nums[i]);
            else if (nums[i] == 2) swap(nums[r--], nums[i--]);
        }

    }
};

// 2,0,2,0,1,0
// l = 0, r = 5
// i = 0: swap, 0 0 2 0 1 2, r = 4, i = -1
// i = 0, swap, 0 0 2 0 1 2, l = 1
// i = 1: swap, 0 0 2 0 1 2, l = 2
// i = 2: swap, 0 0 1 0 2 2, r = 3, i = 1
// i = 2: no move
// i = 3: swap, 0 0 0 1 2 2, l = 3
// i = 4 > r, stop

/*
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Sort Colors.
Memory Usage: 8.6 MB, less than 59.35% of C++ online submissions for Sort Colors.
*/
