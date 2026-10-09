class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        nums.insert(nums.begin(),0);
        dp[1]=0;
        if(abs(nums[2]-nums[1])<=target) dp[2]=1;
        for(int i=3;i<=n;i++)
        {
            int j=i-1;
            while(j>0)
            {
                if(abs(nums[i]-nums[j])<=target && (dp[j]!=0||j==1))
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
                j--;
            }
        }
        if(dp[n]==0) return -1;
        return dp[n];
    }
};