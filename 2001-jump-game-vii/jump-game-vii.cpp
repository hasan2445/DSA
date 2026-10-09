
class Solution {
public:
    bool canReach(string s, int mn, int mx) {
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 1;

        int reachable = 0;

        for (int i = mn; i < n; i++) {
            if (i - mn >= 0)
                reachable += dp[i - mn];

            if (i - mx - 1 >= 0)
                reachable -= dp[i - mx - 1];

            if (s[i] == '0' && reachable > 0)
                dp[i] = 1;
        }

        return dp[n - 1];
    }
};
