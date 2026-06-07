class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        prices.insert(prices.begin(), 0);

        vector<vector<long long>> dp(
            n + 1,
            vector<long long>(k + 1, 0)
        );

        for (int x = 1; x <= k; x++) {

            long long bestBuy  = dp[0][x - 1] - prices[1];
            long long bestSell = dp[0][x - 1] + prices[1];

            for (int i = 1; i <= n; i++) {

                dp[i][x] = dp[i - 1][x];

                dp[i][x] = max(
                    dp[i][x],
                    max(bestBuy + prices[i],
                        bestSell - prices[i])
                );

                bestBuy = max(
                    bestBuy,
                    dp[i - 1][x - 1] - prices[i]
                );

                bestSell = max(
                    bestSell,
                    dp[i - 1][x - 1] + prices[i]
                );
            }
        }

        return dp[n][k];
    }
};