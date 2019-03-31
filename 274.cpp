// https://leetcode.com/problems/h-index/
/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

Example:

Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had
             received 3, 0, 6, 1, 5 citations respectively.
             Since the researcher has 3 papers with at least 3 citations each and the remaining
             two with no more than 3 citations each, her h-index is 3.
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {

        map<int, int> m;
        for (int i : citations) {
            if (m.find(i) != m.end()) m[i]++;
            else m[i] = 1;
        }
        int currCount = 0;
        int index = 0;
        for (auto i : citations)
            if (i > index) index = i;
        for (int i = index; i >= 0; i--) {
            if (m.find(i) == m.end()) ;
            else currCount += m[i];
            if (currCount >= i) return i;
        }
        return 0;
    }
};

/*
Runtime: 4 ms, faster than 100.00% of C++ online submissions for H-Index.
Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for H-Index.
*/