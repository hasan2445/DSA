class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = ans | nums[i];
        }
            vector<vector<int>> dp(n, vector<int>(ans + 1, 0));
        
        dp[0][0] = 1;         
        dp[0][nums[0]] += 1;   
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= ans; j++) {
                if (dp[i-1][j] > 0) {
                    dp[i][j] += dp[i-1][j];
                    dp[i][j | nums[i]] += dp[i-1][j];
                }
            }
        }
        
        return dp[n-1][ans];
    }
};
