/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& A) {
        vector<int> res;
        if (A.empty()) return res;

        int sz = A.size();
        sort(begin(A), end(A));
        vector<int> dp(sz,1);
        vector<int> prev(sz, -1);
        int max_idx = 0;

        for (int i = 1; i < sz; ++i){
	        for (int j = 0; j < i; ++j){
		        if (A[i]%A[j] == 0 && dp[i] < dp[j]+1){
			        dp[i] = dp[j] + 1;
			        prev[i] = j;
		        }
	        }
	        if (dp[i] > dp[max_idx]) max_idx = i;
        }

        for(int i = max_idx; i >= 0; )  res.push_back(A[i]), i = prev[i];

        return res;
    }
};
