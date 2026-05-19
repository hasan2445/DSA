class Solution {
public:
    bool check(string s,int j,int i)
    {
        long long value=1;
        long long sum=0;
      for(int x=i;x>=j;x--)
      {
        sum+=value*(s[x]-'0');
        value=value<<1;

      }
     // if(sum==1) return true;
      while(sum>=5)
      {
        if(sum%5==0)
        {
            sum/=5;
        }
        
        else
        {
            return false;
        }
      }
      if(sum==1) return true;
      return false;
    }
    int minimumBeautifulSubstrings(string s) {
        if(s[0]=='0') return -1;
        int n=s.size();
        s.insert(s.begin(),'0');
        vector<int>dp(n+1,1e9);
        if(s[1]=='1') dp[1]=1;
        else dp[1]=0;
        dp[0]=0;
        
        for(int i=2;i<=n;i++)
        {
            int j=i;
           
            while(j>0)
            {
                if( s[j]!='0')
                {
                    
                   if(check(s,j,i) )
                   {
                    dp[i]=min(dp[j-1]+1,dp[i]);
                   }
                }
                j--;
            }

        }
       return dp[n] >= 1e9 ? -1 : dp[n];
    }
};