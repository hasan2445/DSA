class Solution {
public:
    int stoneGameV(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        vector<int>pre(n+1,0);
        pre[0]=0;
        
        for(int i=1;i<=n;i++)
        {
            pre[i]=arr[i-1]+pre[i-1];
        }
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i+len-1<n;i++)
            {
                int j=i+len-1;
                for(int k=i;k<j;k++)
                {
                    int s1=pre[k+1]-pre[i];
                    int s2=pre[j+1]-pre[k+1];
                    if(s1<s2)
                    {
                        dp[i][j]=max(dp[i][j],s1+dp[i][k]);
                    }
                   else if(s1 > s2) {
                        dp[i][j] = max(dp[i][j], s2 + dp[k + 1][j]);
                    }
                    else {
                        dp[i][j] = max(dp[i][j],
                            max(s1 + dp[i][k],
                                s2 + dp[k + 1][j]));
                    }
                    
                    
                }
            }

        }
        return dp[0][n-1];
    }
};