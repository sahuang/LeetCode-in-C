// https://leetcode.com/problems/merge-intervals/
/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {

        vector<Interval> ans;
        if (intervals.size() == 0) return ans;

        // customised sort: sort on second then first
        auto lambda = []
            (const Interval& x, const Interval& y) -> bool {
            return x.start < y.start ||
                (x.start == y.start && x.end < y.end);
        };
        sort(intervals.begin(), intervals.end(), lambda);

        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i].start;
            int end = intervals[i].end;
            while (i < intervals.size() - 1 &&
                  end >= intervals[i + 1].start) {
                i++;
                end = max(end, intervals[i].end);
            }
            Interval temp(start, end);
            ans.push_back(temp);
        }

        return ans;
    }
};

/*
Runtime: 12 ms, faster than 99.43% of C++ online submissions for Merge Intervals.
Memory Usage: 9.9 MB, less than 99.81% of C++ online submissions for Merge Intervals.
*/
