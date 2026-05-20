class Solution {
public:
    bool check(int freq[])
    {
        int value=0;
       for(int k=0;k<26;k++)
       {
        if(freq[k]!=0)
        {
        if(value==0) value=freq[k];
        else
        {
            if(freq[k]!=value)return false;

        }
        }

       }
       return true;
    }
    int minimumSubstringsInPartition(string s) {
        int n=s.size();
        s.insert(s.begin(),'0');
        vector<int>dp(n+1,1e9);
        dp[0]=0;
        dp[1]=1;
        for(int i=1;i<=n;i++)
        {
            int j=i;
            int freq[26]={0};
            while(j>=1)
            {
            freq[s[j]-'a']++;
            if(check(freq)) 
            {
                dp[i]=min(1+dp[j-1],dp[i]);
            }
            j--;
            }

        }
        return dp[n]>=1e9?-1:dp[n];
    }
};