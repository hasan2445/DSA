class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        s="0"+s;
        int x=1;
        int y=1;
        for(int i=1;i<=n;i++)
        {
            dp[i][i]=1;

        }
        for(int len=2;len<=n;len++)
        {
            for(int i=1;i+len-1<=n;i++)
            {
                int j=i+len-1;
                if(len==2)
                {
                    if(s[i]==s[j]) 
                    {
                        x=i;
                        y=j;
                        dp[i][j]=1;
                    }

                }
                if(s[i]==s[j])
                {
                    if(dp[i+1][j-1])
                    {
                        x=i;
                        y=j;
                        dp[i][j]=1;
                    }
                }
            }

        }
        return s.substr(x,y-x+1);
    }
};