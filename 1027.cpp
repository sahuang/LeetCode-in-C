// https://leetcode.com/problems/longest-arithmetic-sequence/

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int ans = 2;
        for (int i = 0; i < A.size() - 2; i++) {
            for (int j = i + 1; j < A.size() - 1; j++) {
                int count = 2;
                int curr = A[j] + A[j] - A[i];
                int k = j + 1;
                while (k < A.size()) {
                    if (A[k] == curr) {
                        count++;
                        curr += A[j] - A[i];
                    }
                    k++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};

/*
Runtime: 2588 ms, faster than 100.00% of C++ online submissions for Longest Arithmetic Sequence.
Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Longest Arithmetic Sequence.
*/
