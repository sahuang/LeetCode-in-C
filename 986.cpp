// https://leetcode.com/problems/interval-list-intersections/
/*
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

Example 1:
Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.
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
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {

        vector<Interval> ans;
        if (!A.size() || !B.size()) return ans;
        int i = 0;
        int j = 0;
        while (i < A.size() && j < B.size()) {
            vector<Interval> temp = bound(A[i], B[j]);
            if (!temp.size()) {
                if (A[i].end < B[j].start) i++;
                else j++;
            } else {
                ans.push_back(temp[0]);
                if (A[i].end < B[j].end) i++;
                else j++;
            }
        }

        return ans;
    }

    vector<Interval> bound(Interval a, Interval b) {
        vector<Interval> ans;
        int lo = max(a.start, b.start);
        int hi = min(a.end, b.end);
        if (lo <= hi) {
            Interval t(lo, hi);
            ans.push_back(t);
        }
        return ans;
    }
};

/*
accepted
*/
