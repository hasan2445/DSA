class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {

        s.insert(s.begin(), '0');

        int n = s.size();

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(n, vector<int>(k + 1, 0))
        );

        for (int len = 1; len <= 2; len++) {

            for (int i = 1; i + len - 1 < n; i++) {

                int j = i + len - 1;

                for (int op = 0; op <= k; op++) {

                    if (len == 1) {

                        dp[i][j][op] = 1;
                    }
                    else {

                        dp[i][j][op] = max(
                            dp[i + 1][j][op],
                            dp[i][j - 1][op]
                        );

                        if (s[i] == s[j]) {

                            dp[i][j][op] = max(
                                dp[i][j][op],
                                2
                            );
                        }
                        else {

                            int cost = min(
                                abs(s[i] - s[j]),
                                26 - abs(s[i] - s[j])
                            );

                            if (op >= cost) {

                                dp[i][j][op] = max(
                                    dp[i][j][op],
                                    2
                                );
                            }
                        }
                    }
                }
            }
        }

        for (int len = 3; len < n; len++) {

            for (int i = 1; i + len - 1 < n; i++) {

                int j = i + len - 1;

                for (int op = 0; op <= k; op++) {

                   

                    if (s[i] == s[j]) {

                        dp[i][j][op] = 2 + dp[i + 1][j - 1][op];
                    }
                    else {

                        int cost = min(
                            abs(s[i] - s[j]),
                            26 - abs(s[i] - s[j])
                        );
                         dp[i][j][op] = max(
                        dp[i + 1][j][op],
                        dp[i][j - 1][op]
                    );

                        if (op >= cost) {

                            dp[i][j][op]=max(dp[i][j][op],2 + dp[i + 1][j - 1][op - cost]);
                            
                        }
                    }
                }
            }
        }

        return dp[1][n - 1][k];
    }
};