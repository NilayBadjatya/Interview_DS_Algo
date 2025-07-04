class Solution {
public:

    int solve(vector<int>& coins, long long curr, int amount, vector<int>& dp){
        if(curr > amount){
            return 1e9;
        }
        if(curr == amount){
            return 0;
        }
        if(dp[curr] != -1){
            return dp[curr];
        }
        int take = 1e9;
        for(int i = 0; i < coins.size(); i++){
            take = min(take, 1 + solve(coins, curr + coins[i], amount, dp));
        }
        return dp[curr] = take;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(1e4+1, -1);
        int ans = solve(coins, 0, amount, dp);
        return ans == 1e9 ? -1 : ans;
    }
};
