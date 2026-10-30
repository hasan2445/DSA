class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
       // if(nums1[0]==nums2[0]) dp[0][0]=1;
        vector<vector<int>>dp(n,vector<int>(m,0));
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    if(i-1>=0 && j-1 >=0) dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=1;
                }
                
                mx=max(mx,dp[i][j]);
            }
        }
        return mx;
        
    }
};