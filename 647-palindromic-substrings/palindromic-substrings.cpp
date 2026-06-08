class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        s.insert(s.begin(),'0');
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int count=0;
        for(int i=1;i<=n;i++)
        {
            dp[i][i]=1;
            count++;
        }
        for(int len=2;len<=n;len++)
        {
            for(int i=1;i+len-1<=n;i++)
            {
                int j=i+len-1;
                if(s[i]==s[j])
                {
                    if(len==2)
                    {
                        dp[i][j]=1;
                        count++;
                        continue;
                    }
                    if(dp[i+1][j-1]==1)
                    {
                        dp[i][j]=1;
                        count++;
                    }
                }

            }
        }
        return count;

    }
};