
class Solution {
public:
    int minCost(int m, vector<int>& cuts) {
        int n = cuts.size();

        cuts.push_back(0);
        cuts.push_back(m);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                int cost = cuts[j + 1] - cuts[i - 1];
                dp[i][j] = INT_MAX;

                for (int k = i; k <= j; k++) {
                    int curr = cost + dp[i][k - 1] + dp[k + 1][j];
                    dp[i][j] = min(dp[i][j], curr);
                }
            }
        }

        return dp[1][n];
    }
};
