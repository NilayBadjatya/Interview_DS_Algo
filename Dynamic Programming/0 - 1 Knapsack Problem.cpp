class Solution {
  public:
    int dp[1001][1001];
    int solve(vector<int> &val, vector<int> &wt, int i, int W){
        if(W < 0){
            return -1e9;
        }
        if(i == val.size() || W == 0){
            return 0;
        }
        if(dp[i][W] != -1){
            return dp[i][W];
        }
        int take = val[i] + solve(val, wt, i+1, W-wt[i]);
        int skip = solve(val, wt, i+1, W);
        return dp[i][W] = max(take, skip);
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        memset(dp, -1, sizeof(dp));
        return solve(val, wt, 0, W);
    }
};
