class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2,1));
        for(int i=1;i<n;i++)
        {
            int j=i-1;
            while(j>=0)
            {
                if(nums[i]>nums[j])
                {
                    dp[i][0]=max(1+dp[j][1],dp[i][0]);
                }
                else if(nums[i]<nums[j]) dp[i][1]=max(1+dp[j][0],dp[i][1]);
                j--;
            }

        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};