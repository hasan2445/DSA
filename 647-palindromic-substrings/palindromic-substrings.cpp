class Solution {
public:
    int countSubstrings(string s) {
        s.insert(s.begin(),'0');
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int count=0;
        for(int len=1;len<n;len++)
        {
            for(int i=1;i+len-1<n;i++)
            {
                if(len==1)
                {
                    count++;
                    dp[i][i]=1;
                    continue;
                }
                int j=i+len-1;
                if(len==2)
                {
                    if(s[i]==s[j])
                    {
                        count++;
                        dp[i][j]=1;
                    }
                }
                
                if(dp[i+1][j-1]==1 && s[i]==s[j])
                {
                     dp[i][j]=1;
                     count++;
                }
            }
        }
        return count;
    }
};