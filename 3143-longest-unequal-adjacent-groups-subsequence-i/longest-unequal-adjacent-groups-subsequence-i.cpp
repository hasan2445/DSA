class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        if (n == 0) return {}; 
        vector<vector<string>> dp(n);
                for(int i = 0; i < n; i++) {
            dp[i] = {words[i]};
        }
        vector<string> ans = dp[0];
        for(int i = 0; i < groups.size(); i++)
        {
            int j = i - 1;
            while(j >= 0)
            {
                if(groups[i] != groups[j])
                {
                   if(dp[i].size() < dp[j].size() + 1)
                   {
                        dp[i] = dp[j];
                        dp[i].push_back(words[i]); 
                   }
                }
                if(ans.size() < dp[i].size()) {
                    ans = dp[i];
                }
                j--;
            }
        }
        return ans;
    }
};
