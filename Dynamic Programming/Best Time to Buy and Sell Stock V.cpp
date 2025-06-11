class Solution {
public:
    long long dp[1001][1001][4];
    long long solve(vector<int>& prices, int i, int k, int s) {
        if (i == prices.size()) {
            if (k >= 0 && s == 0) {
                return 0;
            }
            return INT_MIN;
        }

        if (dp[i][k][s] != -1) {
            return dp[i][k][s];
        }

        long long take = INT_MIN, skip = INT_MIN;
        if (k > 0) {
            if (s == 0) {
                take = -prices[i] + solve(prices, i + 1, k, 1);
                take = max(take, prices[i] + solve(prices, i + 1, k, 2));
            } else if (s == 1) {
                take = prices[i] + solve(prices, i + 1, k - 1, 0);
            } else {
                take = -prices[i] + solve(prices, i + 1, k - 1, 0);
            }
        }
        skip = solve(prices, i + 1, k, s);

        return dp[i][k][s] = max(take, skip);
    }

    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, k, 0);
    }
};
