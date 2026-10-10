class Solution {
public:
    int countSubstrings(string s) {
      int n=s.size();
      s=" "+s;
      vector<vector<int>>dp(n+1,vector<int>(n+1,0));
      int cnt=0;
      for(int i=1;i<=n;i++)
      {
        dp[i][i]=1;
        cnt++;
      }
      for(int len=2;len<=n;len++)
      {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if(len==2 && s[i]==s[j])
            {
                dp[i][j]=1;
                cnt++;
                continue;
            }
            if(s[i]==s[j])
            {
                dp[i][j]=dp[i+1][j-1];
                if(dp[i][j]) cnt++;
            }
        }
      }  
      return cnt;
    }
};