class Solution {
public:
    bool wordBreak(string s, vector<string>& word) {
        int n=s.size();
        vector<bool>dp(n+1,false);
        s.insert(s.begin(),'0');
        unordered_set<string>st;
        for(int i=0;i<word.size();i++)
        {
            st.insert(word[i]);
        }
        dp[0]=true;
        for(int i=1;i<=n;i++)
        {
            int j=i;
            while(j>0)
            {
                if(dp[j-1] && st.count(s.substr(j,i-j+1)))
                {
                    dp[i]=true;
                }
                j--;
            }
        }
        return dp[n];
    }
};