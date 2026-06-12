class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> dp;
        int maxLength = 1;
        for (int num : arr) {
            int target = num - diff;
            
            if (dp.count(target)) {
                dp[num] = dp[target] + 1;
            } else {
                dp[num] = 1;
            }
            maxLength = max(maxLength, dp[num]);
        }
        
        return maxLength;
    }
};
