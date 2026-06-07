class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pref(n+1,0);
        pref[0]=0;
        nums.insert(nums.begin(),0);
        
        //pref[1]=nums[1];
        for(int i=1;i<=n;i++)
        {
            pref[i]=pref[i-1]+nums[i];
        }
        vector<vector<double>>dp(n+1,vector<double>(k+1,0));
        for(int i=1;i<=n;i++)
        {
               dp[i][1] = (double)pref[i] / i;     
       }
        for(int i=1;i<=n;i++)
        {
            int j=i;
            while(j>0)
            {
               double avg = (double)(pref[i]-pref[j-1])/(i-j+1);  
              for(int x=2;x<=k;x++)
                {
                    dp[i][x]=max(dp[i][x],dp[j-1][x-1]+avg);

                }
                j--;
            }
        }
        return dp[n][k];
        
        
    }
};