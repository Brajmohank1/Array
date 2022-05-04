/*
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

Example 1:

Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]
Example 2:

Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83
Example 3:

Input: arr = [1], k = 1
Output: 1

*/

/*
dp[i] record the maximum sum we can get considering A[0] ~ A[i-1]
To get dp[i], we will try to change k last numbers separately to the maximum of them,
where k = 1 to k = K.

Solution 1, O(N) space
Time O(NK)
Space O(N)
*/


int maxSumAfterPartitioning(vector<int>& A, int K) {
        int N = A.size();
        vector<int> dp(N + 1);
        for (int i = 1; i <= N; ++i) {
            int curMax = 0, best = 0;
            for (int k = 1; k <= K && i - k >= 0; ++k) {
                curMax = max(curMax, A[i - k]);
                best = max(best, dp[i - k] + curMax * k);
            }
            dp[i] = best; 
        }
        return dp[N];
    }
