class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();
        s.insert(s.begin(),'0');
        vector<int>dp(n+1,0);
        unordered_set<string>st;
        for(int i=0;i<dictionary.size();i++)
        {
            st.insert(dictionary[i]);
        }
        for(int i=1;i<=n;i++)
        {
            int j=i;
            dp[i]=1+dp[i-1];
            while(j>0)
            {
                
                
                if(st.count(s.substr(j,i-j+1)))
                {
                    dp[i]=min(dp[i],dp[j-1]);
                }
                 
                j--;
            }

        }
        return dp[n];
    }
};