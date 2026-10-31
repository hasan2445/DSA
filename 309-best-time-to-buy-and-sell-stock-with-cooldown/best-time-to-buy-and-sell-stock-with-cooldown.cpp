class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        vector<int>dp(n,0);
        for(int i=1;i<n;i++)
        {
            int j=i-1;
            while(j>=0)
            {
                if(j-2>=0) dp[i]=max(dp[i],max(nums[i]-nums[j]+dp[j-2],dp[j]));
                else dp[i]=max(dp[i],max(nums[i]-nums[j],dp[j]));
                j--;
            }
            mx=max(mx,dp[i]);
        }
        return mx;
        
        
    }
};