class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>dp(n,1);
        int mx=1;
        for(int i=1;i<n;i++)
        {
            int j=i-1;
            while(j>=0)
            {
                if(pairs[i][0]>pairs[j][1])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
                j--;
                mx=max(dp[i],mx);
            }
        }
        return mx;
    }
};