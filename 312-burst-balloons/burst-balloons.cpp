class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);  
        nums.push_back(1);
        n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int len = 1; len <= n-2; len++)
        {
            for(int i = 1; i + len - 1 < n-1; i++)
            {
                int j = i + len - 1;
                int maxi = 0;
                dp[i][j]=0;
                for(int k = i; k <= j; k++)
                {
                    int cost = nums[k] * nums[i-1] * nums[j+1];
                    dp[i][j] = max(dp[i][j],
                               cost + dp[i][k-1] + dp[k+1][j]);
                }
                //dp[i][j] = maxi;
            }
        }
        return dp[1][n-2];
    }
};
