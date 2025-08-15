class Solution {
  public:
    int solve(vector<vector<int>>& cost, int pos, int mask, int n, vector<vector<int>>& dp){
        if(mask == ((1 << n) - 1)){
            return cost[pos][0];
        }
        if(dp[pos][mask] != -1){
            return dp[pos][mask];
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            if((mask & (1 << i))) continue;
            ans = min(ans, cost[pos][i] + solve(cost, i, mask | (1 << i), n, dp));
        }
        return dp[pos][mask] = ans;
    }
  
    int tsp(vector<vector<int>>& cost) {
        // Code here
        int n = cost.size();
        vector<vector<int>> dp(n+1, vector<int> ((1 << n), -1));
        return solve(cost, 0, 1, n, dp);
    }
};
