class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> pre(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            pre[i] = pre[i-1] + stones[i-1];
        }

        for(int len = 2; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                int leftSum = pre[j+1] - pre[i+1];
                int rightSum = pre[j] - pre[i];

                dp[i][j] = max(
                    leftSum - dp[i+1][j],
                    rightSum - dp[i][j-1]
                );
            }
        }

        return dp[0][n-1];
    }
};