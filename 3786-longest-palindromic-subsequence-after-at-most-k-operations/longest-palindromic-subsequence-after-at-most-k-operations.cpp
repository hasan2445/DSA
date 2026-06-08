class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        s.insert(s.begin(), '0');
        int ans = 1;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, 0)));
        
        for(int i = 1; i <= n; i++) {
            for(int x = 0; x <= k; x++) {
                dp[i][i][x] = 1;
            }
        }
        
        for(int len = 2; len <= n; len++) {
            for(int i = 1; i + len - 1 <= n; i++) {
                int j = i + len - 1;
                int cost = min(abs(s[i] - s[j]), (26 - abs(s[i] - s[j])));
                
                for(int x = 0; x <= k; x++) {
                    dp[i][j][x] = max(dp[i + 1][j][x], dp[i][j - 1][x]);
                    
                    if(s[i] == s[j]) {
                        if(len == 2) {
                            dp[i][j][x] = max(dp[i][j][x], 2);
                        } else {
                            dp[i][j][x] = max(dp[i][j][x], 2 + dp[i + 1][j - 1][x]);
                            ans = len;
                        }
                    } else {
                        if(x >= cost) {
                            if(len == 2) {
                                dp[i][j][x] = max(2, dp[i][j][x]); 
                            } else {
                                dp[i][j][x] = max(dp[i][j][x], dp[i + 1][j - 1][x - cost] + 2);
                            }
                        }
                    }
                }
            }
        }
        return dp[1][n][k];
    }
};
