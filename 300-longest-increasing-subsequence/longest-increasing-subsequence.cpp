class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,1);
        nums.insert(nums.begin(),0);
        dp[0]=0;
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            int j=i;
            while(j>0)
            {
                if(nums[i]>nums[j-1])
                {
                    dp[i]=max(dp[i],dp[j-1]+1);
                }
                j--;
            }
            mx=max(mx,dp[i]);
        }
        return mx;
        
    }
};